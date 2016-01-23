<%@ Page Title="" Language="VB" MasterPageFile="~/ContentMasterPage.master" AutoEventWireup="false" CodeFile="frmAuthorizeGroup.aspx.vb" Inherits="frmAuthorizeGroup" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="Server">
    <form id="form1" runat="server">
        <link href="assets/js/jquery.dynatree-1.2.6-all/skin/ui.dynatree.css" rel="stylesheet" />
        <script src="assets/js/jquery.dynatree-1.2.6-all/jquery.dynatree.js"></script>

        <script type="text/javascript">
            function onValidHide() {
                $("#lblvalidGroupName").hide();
                $("#lblvalidGroupDesc").hide();

            }
            function onValid() {
                var isValid;
                isValid = true;
                var group_name = $('#txtGroupName').val();
                var group_desc = $('#txtGroupDesc').val();
                if (group_name == '') {
                    $("#lblvalidGroupName").show();
                    isValid = false;
                } else {
                    $("#lblvalidGroupName").hide();
                }
                //if (group_desc == '') {
                //    $("#lblvalidGroupDesc").show();
                //    isValid = false;
                //} else {
                //    $("#lblvalidGroupDesc").hide();

                //}

                return isValid;


            }
            function CheckSelect() {
                var ret = true;
                var txt = $("#echoSelection").text();
                if (txt == '') {
                    ret = false
                }

                return ret;
            }

            function CheckIsSave() {
                var ret = CheckSelect();
                if (ret == true) {
                    $("#divSaveMapGroup").show();
                } else {
                    $("#divSaveMapGroup").hide();
                }
            }

            function onSave() {
                var UserID = $('#' + '<%=Master.FindControl("lblUserID").ClientID%>').text();
                var strgroupid = $("#HiddenGroupId").val();
                var txt = $("#echoSelection").text();
                var param = "{'strId':" + JSON.stringify(txt) + ",'groupid':" + JSON.stringify(strgroupid) + ",'userid':" + JSON.stringify(UserID) + "}";

                //alert(param);
                // var param = "{'strID':" + JSON.stringify(value) + "}";

                $.ajax({
                    type: "POST",
                    url: "WebSevice/WebService.asmx/SaveAuthorizeGroup",
                    data: param,
                    contentType: "application/json; charset=utf-8",
                    dataType: "json",
                    success: onSuccess,
                    error: onFailed
                });
            }
            //Save Group
            function onSaveGroup(id) {
                var UserID = $('#' + '<%=Master.FindControl("lblUserID").ClientID%>').text();
        var group_name = $('#txtGroupName').val();
        var group_desc = $('#txtGroupDesc').val();
        var group_active = $('input[name="ckbActive"]:checked').length;
        var param = "{'id':" + JSON.stringify(id) + ",'group_name':" + JSON.stringify(group_name) + ",'group_desc':" + JSON.stringify(group_desc) + ",'userid':" + JSON.stringify(UserID) + ",'active':" + JSON.stringify(group_active) + "}";

        $.ajax({
            type: "POST",
            url: "WebSevice/WebService.asmx/SaveGroup",
            data: param,
            contentType: "application/json; charset=utf-8",
            dataType: "json",
            success: onGroupSuccess,
            error: onFailed
        });
    }
    //Save Group User
    function onSaveGroupUser() {
        var id = $("#txtUserId").val();
        var userid = $('#' + '<%=Master.FindControl("lblUserID").ClientID%>').text();
        var groupid = $("#HiddenGroupId").val();
        var param = "{'id':" + JSON.stringify(id) + ",'groupid':" + JSON.stringify(groupid) + ",'userid':" + JSON.stringify(userid) + "}";

        $.ajax({
            type: "POST",
            url: "WebSevice/WebService.asmx/SaveGroupUser",
            data: param,
            contentType: "application/json; charset=utf-8",
            dataType: "json",
            success: onGroupUserSuccess,
            error: onFailed
        });
    }
    //Detal Group
    function onDeleteGroup(id) {
        var param = "{'id':" + JSON.stringify(id) + "}";

        $.ajax({
            type: "POST",
            url: "WebSevice/WebService.asmx/DeleteGroup",
            data: param,
            contentType: "application/json; charset=utf-8",
            dataType: "json",
            success: onDeleteSuccess,
            error: onDeleteFailed
        });
    }
    //Detal Group
    function onDeleteGroupUser(id) {
        var param = "{'id':" + JSON.stringify(id) + "}";

        $.ajax({
            type: "POST",
            url: "WebSevice/WebService.asmx/DeleteGroupUser",
            data: param,
            contentType: "application/json; charset=utf-8",
            dataType: "json",
            success: onDeleteGroupUserSuccess,
            error: onDeleteFailed
        });
    }

    //Alert Save when true
    function onSuccess(result) {

        if (result.d == true) {
            onAlert("Save Complete");

        } else {
            onAlert("Save Fail");
        }

    }
    //Group  Alert  True
    function onGroupSuccess(result) {

        if (result.d == "YES") {
            $("#dialog-edit").dialog('close');
            onAlert("Save Complete");
            LoadData();
        } else {
            if (result.d == "DUPLICATE") {
                onAlert("Group name already exists. Please modify group name.");
                LoadData();
            } else {
                onAlert("Save Fail");
            }

        }

    }
    //Group User Alert  True
    function onGroupUserSuccess(result) {

        if (result.d == "YES") {
            onAlert("Save Complete");
            LoadDataUser();
        } else {
            if (result.d == "DUPLICATE") {
                onAlert("User already exists. Please modify user.");
                LoadDataUser();
            } else {
                onAlert("Save Fail");
            }
        }

    }
    //Alert Save when false
    function onFailed() {
        onAlert("Save Fail");
    }
    //Alert Delete when true
    function onDeleteSuccess(result) {

        if (result.d == true) {
            onAlert("Delete Complete");
            $("#divmenuaccess").hide();
            $("#divgroup").removeClass("span7");
            $("#divgroup").addClass("span11");
            $("#divmenuaccess").removeClass("span1");
            $("#divmenuaccess").addClass("span5");
            LoadData();

        } else {
            onAlert("Delete Fail");
        }

    }
    //Alert Delete when true
    function onDeleteGroupUserSuccess(result) {

        if (result.d == true) {
            onAlert("Delete Complete");
            LoadDataUser();

        } else {
            onAlert("Delete Fail");
        }

    }
    //Alert Delete when false
    function onDeleteFailed() {
        onAlert("Delete Fail");
    }

    // Confirm Save menu
    function onConfirm(id) {
        var ret = CheckSelect();
        if (ret == false) {
            onAlert("Please select menu");
            return;
        }
        var msg = 'Please confirm the save';
        var div = $("<div>" + msg + "</div>");
        div.dialog({
            title: "Confirm",
            modal: true,
            buttons: [
                        {
                            text: "Yes",
                            click: function () {
                                div.dialog("close");
                                onSave();
                            }
                        },
                        {
                            text: "No",
                            click: function () {
                                div.dialog("close");
                            }
                        }
            ]
        });



    }

    // Confirm save group
    function onConfirmGroup(id) {


        var msg = 'Please confirm the save';
        var div = $("<div>" + msg + "</div>");
        div.dialog({
            title: "Confirm",
            modal: true,
            buttons: [
                        {
                            text: "Yes",
                            click: function () {
                                div.dialog("close");
                                onSaveGroup(id);

                            }
                        },
                        {
                            text: "No",
                            click: function () {
                                div.dialog("close");
                            }
                        }
            ]
        });



    }
    //Clear Text Add User
    function ClearTextGroupUser() {
        $("#txtUserName").val("");
        $("#txtUserId").val("");
    }


    // Confirm Group User
    function onConfirmGroupUser() {
        var retanme = $("#txtUserName").val();
        var retid = $("#txtUserId").val();
        if (retid == '') {
            onAlert("Please input name or suranme");
            return;
        }
        var msg = 'Please confirm the save';
        var div = $("<div>" + msg + "</div>");
        div.dialog({
            title: "Confirm",
            modal: true,
            buttons: [
                        {
                            text: "Yes",
                            click: function () {
                                div.dialog("close");
                                onSaveGroupUser();
                            }
                        },
                        {
                            text: "No",
                            click: function () {
                                div.dialog("close");
                            }
                        }
            ]
        });



    }

    //Confirm delete group
    function onConfirmDeleteGroup(id) {

        var msg = 'Please confirm the delete';
        var div = $("<div>" + msg + "</div>");
        div.dialog({
            title: "Confirm",
            modal: true,
            buttons: [
                        {
                            text: "Yes",
                            click: function () {
                                div.dialog("close");
                                onDeleteGroup(id);

                            }
                        },
                        {
                            text: "No",
                            click: function () {
                                div.dialog("close");
                            }
                        }
            ]
        });



    }
    //Confirm delete group user
    function onConfirmDeleteGroupUser(id) {

        var msg = 'Please confirm the delete';
        var div = $("<div>" + msg + "</div>");
        div.dialog({
            title: "Confirm",
            modal: true,
            buttons: [
                        {
                            text: "Yes",
                            click: function () {
                                div.dialog("close");
                                onDeleteGroupUser(id);

                            }
                        },
                        {
                            text: "No",
                            click: function () {
                                div.dialog("close");
                            }
                        }
            ]
        });



    }

    // Alert
    function onAlert(msg) {

        var div = $("<div>" + msg + "</div>");
        div.dialog({
            title: "Message",
            modal: true,
            buttons: [

                        {
                            text: "Ok",
                            click: function () {
                                div.dialog("close");
                            }
                        }
            ]
        });

    }

    //Grid
    function LoadData() {
        var dataurl = 'frmAuthorizeGroupGetGroupData.ashx';
        $.ajax({
            "type": "POST",
            "dataType": 'json',
            "contentType": "application/json; charset=utf-8",
            "url": dataurl,
            "success": PopulateGrid
        });
    }

    function PopulateGrid(jsondata) {
        var columns = [{
            "sTitle": "No",
            "sType": "numeric",
            "mDataProp": "no",
            "bUseRendered": false

        },
                        {
                            "sTitle": "Group Name",
                            "sType": "string",
                            "sDefaultContent": "",
                            "mDataProp": "group_name"

                        },
                        //{
                        //    "sTitle": "Group Description",
                        //    "sType": "string",
                        //    "sDefaultContent": "",
                        //    "mDataProp": "group_desc"

                        //},
                        {
                            "sTitle": "Active",
                            "sType": "string",
                            "sDefaultContent": "",
                            "mDataProp": "active_status_desc"

                        },

                        {
                            "sTitle": "Action",
                            "bSortable": false,
                            "fnRender": function (obj) {
                                return '<div class="hidden-phone visible-desktop action-buttons">'
                                        + '<a href="#"  data-toggle="modal" class="blue"  title="Authorized" onClick="onMapmenu(' + obj.aData.id + ');">'
                                        + '<span class="blue"><i class="icon-lock bigger-130"></i></span>'
                                        + '</a>'
                                        + '&nbsp;'
                                        + '<a href="#"  class="Green"  title="Edit" onClick="onEdit(' + obj.aData.id + ');">'
                                        + '<span class="green"><i class="icon-pencil bigger-130"></i></span>'
                                        + '</a>'
                                        + '&nbsp;'
                                        + '<a href="#"  class="Red"  title="Delete" onclick="onConfirmDeleteGroup(' + obj.aData.id + ');" >'
                                        + '<span class="red"><i class="icon-trash bigger-130"></i></span>'
                                        + '</a>'
                                        + '</div>'
                                        + '<div class="hidden-desktop visible-phone">'
                                        + '			<div class="inline position-relative">'
                                        + '				<button class="btn btn-minier btn-primary dropdown-toggle" data-toggle="dropdown">'
                                        + '					<i class="icon-cog icon-only bigger-110"></i>'
                                        + '				</button>'
                                        + ''
                                        + '				<ul class="dropdown-menu dropdown-icon-only dropdown-yellow pull-right dropdown-caret dropdown-close">'
                                        + '					<li>'
                                        + '						<a href="#"  class="tooltip-info" data-rel="tooltip" title="Authorized" onClick="onMapmenu(' + obj.aData.id + ');">'
                                        + '							<span class="blue">'
                                        + '								<i class="icon-lock bigger-120"></i>'
                                        + '							</span>'
                                        + '						</a>'
                                        + '					</li>'
                                        + ''
                                        + '					<li>'
                                        + '						<a href="#"   class="tooltip-success" data-rel="tooltip" title="Edit" onClick="onEdit(' + obj.aData.id + ');">'
                                        + '							<span class="green">'
                                        + '								<i class="icon-edit bigger-120"></i>'
                                        + '							</span>'
                                        + '						</a>'
                                        + '					</li>'
                                        + ''
                                        + '					<li>'
                                        + '						<a href="#"  class="tooltip-error" data-rel="tooltip" title="Delete" onclick="onConfirmDeleteGroup(' + obj.aData.id + ');">'
                                        + '							<span class="red">'
                                        + '								<i class="icon-trash bigger-120"></i>'
                                        + '							</span>'
                                        + '						</a>'
                                        + '					</li>'
                                        + '				</ul>'
                                        + '			</div>'
                                        + '		</div>'


                                ;
                            },
                            "sDefaultContent": "",
                            "bUseRendered": false
                        }
        ];

        oTable = $('#dt_out').dataTable({
            "aaData": jsondata,
            "bAutoWidth": false,
            "aoColumnDefs": [
            { "sWidth": "10%", "aTargets": [0] },
            { "sWidth": "60%", "aTargets": [1] },
         //   { "sWidth": "35%", "aTargets": [2] },
            { "sWidth": "15%", "aTargets": [2] },
            { "sWidth": "15%", "aTargets": [3] }
            ],
            "aoColumns": columns,
            "bDestroy": true,
        });


    }


    function LoadDataUser() {

        ClearTextGroupUser();

        var groupid = $("#HiddenGroupId").val();
        var paramsend = "{'groupid':" + JSON.stringify(groupid) + "}";
        var dataurl = 'WebSevice/WebService.asmx/GetUserMapAuthorizeGroup';
        $.ajax({
            "type": "POST",
            "dataType": 'json',
            "contentType": "application/json; charset=utf-8",
            "url": dataurl,
            "data": paramsend,
            "success": PopulateGridUser
        });
    }

    function PopulateGridUser(jsondataUser) {
        var jsonobject = JSON.parse(jsondataUser.d);
        var columns = [{
            "sTitle": "No",
            "sType": "numeric",
            "mDataProp": "no",
            "bUseRendered": false

        },

                        {
                            "sTitle": "Name - Surname",
                            "sType": "string",
                            "sDefaultContent": "",
                            "mDataProp": "fullname_eng"

                        },


                        {
                            "sTitle": "Action",
                            "bSortable": false,
                            "fnRender": function (objUser) {
                                return '<div class="hidden-phone visible-desktop action-buttons">'
                                        + '<a href="#"  class="Red"  title="Delete" onclick="onConfirmDeleteGroupUser(' + objUser.aData.id + ');" >'
                                        + '<span class="red"><i class="icon-trash bigger-130"></i></span>'
                                        + '</a>'
                                        + '</div>'
                                                    + '<div class="hidden-desktop visible-phone">'
                                        + '			<div class="inline position-relative">'
                                        + '				<button class="btn btn-minier btn-primary dropdown-toggle" data-toggle="dropdown">'
                                        + '					<i class="icon-cog icon-only bigger-110"></i>'
                                        + '				</button>'
                                        + ''
                                        + '				<ul class="dropdown-menu dropdown-icon-only dropdown-yellow pull-right dropdown-caret dropdown-close">'
                                        + ''
                                        + '					<li>'
                                        + '						<a href="#"  class="tooltip-error" data-rel="tooltip" title="Delete" onclick="onConfirmDeleteGroupUser(' + objUser.aData.id + ');">'
                                        + '							<span class="red">'
                                        + '								<i class="icon-trash bigger-120"></i>'
                                        + '							</span>'
                                        + '						</a>'
                                        + '					</li>'
                                        + '				</ul>'
                                        + '			</div>'
                                        + '		</div>'


                                ;
                            },
                            "sDefaultContent": "",
                            "bUseRendered": false
                        }
        ];

        oTableUser = $('#dt_user').dataTable({
            "aaData": jsonobject,
            "bAutoWidth": false,
            "aoColumnDefs": [
            { "sWidth": "15%", "aTargets": [0] },
            { "sWidth": "70%", "aTargets": [1] },
            { "sWidth": "15%", "aTargets": [2] }
            ],
            "aoColumns": columns,
            "bDestroy": true,
        });


    }

    function onEdit(id) {
        onValidHide();
        var param = "{'groupid':" + JSON.stringify(id) + "}";

        $.ajax({
            type: "POST",
            url: "WebSevice/WebService.asmx/LoadAuthorizeGroup",
            data: param,
            contentType: "application/json; charset=utf-8",
            dataType: "json",
            success: function (data) {
                var strvalue = JSON.parse(data.d);
                if (strvalue.length == 1) {
                    $("#txtGroupName").val(strvalue[0].group_name);
                    $("#txtGroupDesc").val(strvalue[0].group_desc);
                    if (strvalue[0].active_status == "Y") {
                        $("#ckbActive").prop("checked", true);
                    } else {
                        $("#ckbActive").prop("checked", false);
                    }
                } else {
                    $("#txtGroupName").val("");
                    $("#txtGroupDesc").val("");
                    $("#ckbActive").prop("checked", false);
                }
            },
            error: onFailed
        });



        $("#dialog-edit").dialog({
            autoOpen: false,
            resizable: false,
            width: "400px",
            modal: true,
            buttons: {
                "Save": function () {
                    var ret = onValid();
                    if (ret == true) {
                        onSaveGroup(id);
                    }

                },
                "Close": function () {
                    $(this).dialog("close");
                }

            },
            show: {
                effect: 'size',
                duration: 500
            },
            hide: {
                effect: 'size',
                duration: 500
            }
        });

        var titledialog;
        if (id == 0) {
            titledialog = "Add New";
        } else {
            titledialog = "Edit";
        }

        $("#dialog-edit").dialog("option", "title", titledialog).dialog("open");

    }

    function onMapmenu(id) {
        $("#HiddenGroupId").val(id);
        // location.reload();
        populatelistmenu();
        LoadDataUser();
        //Listmenu Name - Surname
        $("#tree1").dynatree("getTree").reload();
        $("#divmenuaccess").show();


        var param = "{'groupid':" + JSON.stringify(id) + "}";
        $.ajax({
            type: "POST",
            url: "WebSevice/WebService.asmx/LoadAuthorizeGroup",
            data: param,
            contentType: "application/json; charset=utf-8",
            dataType: "json",
            success: function (data) {
                var strvalue = JSON.parse(data.d);
                if (strvalue.length == 1) {
                    $("#lblMenuheader").text('Permission Access ' + '( Group : ' + strvalue[0].group_name + ' )');
                } else {
                    $("#lblMenuheader").text("");
                }
            }
        });

        //Autocomplete Name - Surname
        $("#txtUserName").autocomplete({
            //   source: data,
            source: function (request, response) {
                $.ajax({
                    type: "POST",
                    url: "WebSevice/WebService.asmx/GetNotUserMapAuthorizeGroup",
                    data: "{ 'name': '" + request.term + "' }",
                    dataType: "json",
                    contentType: "application/json; charset=utf-8",
                    success: function (data) {
                        var jsonobject = JSON.parse(data.d);
                        response(jsonobject);
                    }
                });
            },
            select: function (event, ui) {
                $("#txtUserName").val(ui.item.label);
                $("#txtUserId").val(ui.item.id);
                //  $( "#search" ).val( ui.item.label + " / " + ui.item.actor );
                return false;
            }
        });


        //Set Class 2 Side
        $("#divgroup").removeClass("span11");
        $("#divgroup").addClass("span7")
        $("#divmenuaccess").removeClass("span1");
        $("#divmenuaccess").addClass("span5");






        return false;

    }

    function populatelistmenu() {
        var strgroupid = $("#HiddenGroupId").val();
        var paramsend = "{'groupid':" + JSON.stringify(strgroupid) + "}";
        $("#tree1").dynatree({

            //initAjax: {
            //    url: "frmAuthorizeGroupGetMenu.ashx"
            //},
            initAjax: {
                type: "POST",
                url: "WebSevice/WebService.asmx/LoadAuthorizeGroupMap",
                data: paramsend,
                contentType: "application/json; charset=utf-8",
                dataType: "json"
            },
            checkbox: true,
            selectMode: 3,
            //children: treeData,
            onSelect: function (select, node) {
                // Get a list of all selected nodes, and convert to a key array:
                var selKeys = $.map(node.tree.getSelectedNodes(), function (node) {
                    return node.data.key;
                });
                $("#echoSelection").text(selKeys.join(", "));

                // Get a list of all selected TOP nodes
                var selRootNodes = node.tree.getSelectedNodes(true);
                // ... and convert to a key array:
                var selRootKeys = $.map(selRootNodes, function (node) {
                    return node.data.key;
                });
                $("#echoSelectionRootKeys").text(selRootKeys.join(", "));
                $("#echoSelectionRoots").text(selRootNodes.join(", "));
            },
            onDblClick: function (node, event) {
                node.toggleSelect();
            },
            onKeydown: function (node, event) {
                if (event.which == 32) {
                    node.toggleSelect();
                    return false;
                }
            }
            // The following options are only required, if we have more than one tree on one page:
            //				initId: "treeData",
            //cookieId: "dynatree-Cb3",
            //idPrefix: "dynatree-Cb3-"
            //,
            //onLazyRead: function (node) {
            //    node.appendAjax(
            //      {
            //          type: "POST",
            //          url: "WebSevice/WebService.asmx/LoadAuthorizeGroupMap",
            //          data: paramsend,
            //          contentType: "application/json; charset=utf-8",
            //          dataType: "json",
            //          sleep: 50
            //      });
            //}



        });


        //Get data select
        $.ajax({
            type: "POST",
            url: "WebSevice/WebService.asmx/GetAuthorizeGroupMap",
            data: paramsend,
            contentType: "application/json; charset=utf-8",
            dataType: "json",
            success: getDateSelect
        });



    }

    function getDateSelect(result) {
        $("#echoSelection").text(result.d);

    }

    function getDateSelectFalse() {
        onAlert("Load Fail");
    }

        </script>

        <script type="text/javascript">
            //Start
            $(document).ready(function () {

                //Set Class default
                $("#divgroup").removeClass("span7");
                $("#divgroup").addClass("span11");
                $("#divmenuaccess").removeClass("span5");
                $("#divmenuaccess").addClass("span1");


                //Load Group
                var oTable;
                var oTableUser;
                var isAddNew = false;
                LoadData();

                //Add Click
                $("#btnAdd").click(function () {
                    onEdit(0); return false;
                });


                //Save Group Menu Click
                $("#btnSaveMapGroup").click(function () {
                    onConfirm(0); return false;
                });
                //Save Group User Click
                $("#btnSaveMapUser").click(function () {
                    onConfirmGroupUser(); return false;
                });

                $("#btnClose").click(function () {
                    $("#divmenuaccess").hide();
                    $("#divgroup").removeClass("span7");
                    $("#divgroup").addClass("span11");
                    $("#divmenuaccess").removeClass("span1");
                    $("#divmenuaccess").addClass("span5");
                });

                //Populate Memu
                populatelistmenu();

                //Select All Click
                $("#ckbSelectAll").click(function () {
                    var value = $('input[name="ckbSelectAll"]:checked').length;
                    // var value = $('#ckbSelectAll :checkbox:checked').length;
                    // alert(value0);
                    if (value > 0) {
                        $("#tree1").dynatree("getRoot").visit(function (node) {
                            node.select(true);
                        });

                        $('#ckbSelectAll"').prop('checked', true);


                        return false;

                    } else {
                        $("#tree1").dynatree("getRoot").visit(function (node) {
                            node.select(false);
                        });

                        $('#ckbSelectAll"').prop('checked', false);
                        return false;
                    }

                });

                //text Limit
                //$('textarea[class*=limited]').each(function () {
                //    var limit = parseInt($(this).attr('data-maxlength')) || 100;
                //    $(this).inputlimiter({
                //        "limit": limit,
                //        remText: '%n character%s remaining...',
                //        limitText: 'max allowed : %n.'
                //    });
                //});

                //$('input[class*=limited]').each(function () {
                //    var limit = parseInt($(this).attr('data-maxlength')) || 100;
                //    $(this).inputlimiter({
                //        "limit": limit,
                //        remText: '%n character%s remaining...',
                //        limitText: 'max allowed : %n.'
                //    });
                //});











            });
        </script>



        <div class="main-content">
            <div class="breadcrumbs" id="breadcrumbs">
                <ul class="breadcrumb">
                    <li>
                        <i class="icon-home home-icon"></i>
                        <a href="frmMain.aspx">Home</a>

                        <span class="divider">
                            <i class="icon-angle-right arrow-icon"></i>
                        </span>
                    </li>


                    <li class="active">Authorize Group</li>
                </ul>
                <!--.breadcrumb-->

                <%--            <div class="nav-search" id="nav-search">
                <form class="form-search" />
                <span class="input-icon">
                    <input type="text" placeholder="Search ..." class="input-small nav-search-input" id="nav-search-input" autocomplete="off" />
                    <i class="icon-search nav-search-icon"></i>
                </span>
                </form>
            </div>--%>
                <!--#nav-search-->
            </div>

            <div class="page-content">

                <div class="row-fluid">
                    <div class="span12">
                        <!--PAGE CONTENT BEGINS-->
                        <h3 class="header smaller lighter blue">Authorized Group</h3>

                        <div class="row-fluid">

                            <div class="span7" id="divgroup">
                                <h4 class="user color pink">Group</h4>
                                <div class="row-fluid">
                                    <div class="span12">
                                        <button class="btn btn-small btn-success" id="btnAdd">
                                            <i class=" icon-edit"></i>
                                            Add New
                                        </button>

                                    </div>
                                </div>
                                <div class="space-2"></div>
                                <div class="row-fluid">
                                    <div class="span12">
                                        <table class="table table-striped table-bordered table-hover" id="dt_out"></table>
                                    </div>
                                </div>



                            </div>
                            <div class="span5" id="divmenuaccess" style="display: none">
                                <div class="span11">
                                    <h3 class="user color pink">
                                        <label id="lblMenuheader" style="font-size: medium"></label>
                                    </h3>
                                </div>
                                <div class="span1">
                                    <button class="btn btn-danger btn-small" id="btnClose" name="btnClose">
                                        <i class="icon-remove"></i>
                                    </button>

                                </div>



                                <%--            <div class="span12">
                                    <div class="controls">
                                        <label class="inline">
                                            <input name="rdoIsAdmin" id="rdoIsAdmin" type="radio"  />
                                            <span class="lbl">&nbsp;All</span>
                                        </label>
                                        &nbsp; &nbsp; &nbsp;<label class="inline">
                                            <input name="rdoIsAdmin"  id="rdoNotAdmin"  type="radio" />
                                            <span class="lbl">&nbsp;Custom</span>
                                        </label>
                                  
                                    </div>
                                </div>--%>
                                <div class="tabbable">
                                    <ul class="nav nav-tabs" id="myTab">
                                        <li class="active">
                                            <a data-toggle="tab" href="#home">
                                                <i class="blue icon-check bigger-110 icon-repo"></i>
                                                Menu
                                            </a>
                                        </li>

                                        <li>
                                            <a data-toggle="tab" href="#profile">
                                                <i class="blue icon-user bigger-110"></i>
                                                User
													
                                            </a>
                                        </li>

                                    </ul>

                                    <div class="tab-content">
                                        <div id="home" class="tab-pane in active">

                                            <div class="row-fluid" id="divListheader">
                                                <div class="span3">
                                                    <div class="controls">
                                                        <label class="inline">
                                                            <input name="ckbSelectAll" type="checkbox" id="ckbSelectAll" />
                                                            <span class="lbl">&nbsp;Select All</span>
                                                        </label>
                                                        <%--                &nbsp;&nbsp;&nbsp;
                                               <button class="inline btn btn-small btn-info" id="btnSaveMapGroup2">
                                            <i class="icon-pencil"></i>
                                            Save
                                        </button>--%>
                                                    </div>


                                                </div>


                                                <div class="span9" id="divSaveMapGroup">

                                                    <button class="inline btn btn-small btn-info" id="btnSaveMapGroup">
                                                        <i class="icon-pencil"></i>
                                                        Save
                                                    </button>
                                                </div>


                                            </div>
                                            <div class="row-fluid" id="divListdetail">
                                                <div class="span12">
                                                    <div id="tree1"></div>
                                                    <div style="display:none" >
                                                        <div>Selected keys: <span id="echoSelection"></span></div>
                                                        <div>Selected root keys: <span id="echoSelectionRootKeys"></span></div>
                                                        <div>Selected root nodes: <span id="echoSelectionRoots"></span></div>
                                                    </div>

                                                    <!--PAGE CONTENT ENDS-->
                                                </div>
                                            </div>
                                            <div class="row-fluid">
                                                <div class="span12">
                                                </div>
                                            </div>
                                        </div>

                                        <div id="profile" class="tab-pane">
                                            <div class="row-fluid">
                                                <div class="span6">
                                                    <input type="text" id="txtUserName" style="width: 200px" placeholder="Input Name or Surname">
                                                    <input type="text" id="txtUserId" style="width: 200px; display: none;" placeholder="Id">
                                                </div>
                                                <div class="span6">
                                                    <button class="inline btn btn-small btn-info" id="btnSaveMapUser">
                                                        <i class="icon-pencil"></i>
                                                        Save
                                                    </button>
                                                </div>
                                            </div>
                                            <div class="row-fluid">
                                                <div class="span12">
                                                    <table class="table table-striped table-bordered table-hover" id="dt_user"></table>
                                                </div>
                                            </div>

                                        </div>

                                    </div>
                                </div>


                                <%--<div class="row-fluid" style="display:none" id="divListSave" >
                                    <div class="center" >
                                        <div class="controls">
                                            &nbsp;
                                        <button class="btn btn-small btn-info" id="btnSaveMapGroup" style="width:150px">
                                            <i class="icon-pencil"></i>
                                            Save
                                        </button>
                                        </div>


                                    </div>
                                </div>--%>
                            </div>
                        </div>



                    </div>

                </div>





                <!--/.span-->
            </div>
            <!--/.row-fluid-->
            <!--/.page-content-->

            <!--Dialog-->



            <div id="dialog-edit" style="display: none;">

                <div class="row-fluid">
                    <div class="span12">
                        <!--PAGE CONTENT BEGINS-->
                        <div class="span4">
                            <label class="control-label" id="lblGroupName">Group Name</label>
                        </div>
                        <div class="span8">

                            <input type="text" id="txtGroupName" placeholder="Group Name" class="span12 limited" data-maxlength="50" maxlength="50">
                            <span class="help-inline color red" id="lblvalidGroupName" style="display: none">This field is required</span>
                            <%--    <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
                                <asp:CustomValidator class="control-label" ID="CustomValidator1" runat="server" ErrorMessage="CustomValidator" ClientValidationFunction="TextBox1" ValidateEmptyText="True" Display="Dynamic"></asp:CustomValidator>
                                <asp:RequiredFieldValidator ID="THIS_IS_WORKING" ControlToValidate="txtGroupName"
                                    runat="server" ErrorMessage="Test" Display="Dynamic">
                                </asp:RequiredFieldValidator>--%>
                        </div>

                    </div>
                </div>
                <div class="row-fluid" style="display: none">
                    <div class="span12">
                        <!--PAGE CONTENT BEGINS-->
                        <div class="span4">
                            <label class="control-label" id="lblGroupDesc">Group Desc</label>
                        </div>
                        <div class="span8">
                            <textarea id="txtGroupDesc" placeholder="Group Desc" style="height: 120px; resize: none;" class="span12 limited" data-maxlength="255" maxlength="255"></textarea>
                            <span class="help-inline color red" id="lblvalidGroupDesc" style="display: none">This field is required</span>
                        </div>

                    </div>
                </div>
                <div class="row-fluid">
                    <div class="span4">
                        <label class="control-label" id="lblGroupActive">Active</label>
                    </div>
                    <div class="span8">
                        <div class="controls">
                            <label class="inline">
                                <input name="ckbActive" type="checkbox" id="ckbActive" />
                                <span class="lbl">&nbsp;</span>
                            </label>
                            <%--                &nbsp;&nbsp;&nbsp;
                                               <button class="inline btn btn-small btn-info" id="btnSaveMapGroup2">
                                            <i class="icon-pencil"></i>
                                            Save
                                        </button>--%>
                        </div>
                    </div>
                </div>
                <%--     <div class="row-fluid">
                          
                               <div class="span4"></div>
    <div class="span8">
                                   <button class="btn btn-small btn-info" id="btnSaveDialog" >
                                        <i class="icon-pencil"></i>
                                        Save
                                    </button>
                                
                                    <button class="btn btn-small btn-default" id="btnCloseDialog">
                                        <i class=" icon-cut"></i>
                                        Close
                                    </button>
                           </div>
                         
                       
                       </div>--%>
            </div>


            <input id="HiddenGroupId" type="hidden" value="0" />

            <%--  <div class="hero-unit">
                <h1>Contact Form</h1>

                <div>
                    <input type="email" id="email" required>
                    <input
                        name="emailAgain"
                        data-validation-matches-match="email"
                        data-validation-matches-message="Must match email address entered above">
                    <input
                        type="checkbox"
                        name="terms-and-conditions"
                        required
                        data-validation-required-message="You must agree to the terms and conditions">
                    <input type="checkbox"
                        name="qualityControl[]"
                        value="fast"
                        minchecked="2"
                        data-validation-minchecked-message="Choose two"
                        maxchecked="2"
                        data-validation-maxchecked-message="You can't have it all ways">
                    <button type="submit">trtrtrtrtrt</button>
                </div>




                <div class="ace-settings-container" id="ace-settings-container" style="display: none">
                    <div class="btn btn-app btn-mini btn-warning ace-settings-btn" id="ace-settings-btn">
                        <i class="icon-cog bigger-150"></i>
                    </div>

                    <div class="ace-settings-box" id="ace-settings-box">
                        <div>
                            <div class="pull-left">
                                <select id="skin-colorpicker" class="hide">
                                    <option data-class="default" value="#438EB9" />
                                    #438EB9
									<option data-class="skin-1" value="#222A2D" />
                                    #222A2D
									<option data-class="skin-2" value="#C6487E" />
                                    #C6487E
									<option data-class="skin-3" value="#D0D0D0" />
                                    #D0D0D0
                                </select>
                            </div>
                            <span>&nbsp; Choose Skin</span>
                        </div>

                        <div>
                            <input type="checkbox" class="ace-checkbox-2" id="ace-settings-header" />
                            <label class="lbl" for="ace-settings-header">Fixed Header</label>
                        </div>

                        <div>
                            <input type="checkbox" class="ace-checkbox-2" id="ace-settings-sidebar" />
                            <label class="lbl" for="ace-settings-sidebar">Fixed Sidebar</label>
                        </div>

                        <div>
                            <input type="checkbox" class="ace-checkbox-2" id="ace-settings-breadcrumbs" />
                            <label class="lbl" for="ace-settings-breadcrumbs">Fixed Breadcrumbs</label>
                        </div>

                        <div>
                            <input type="checkbox" class="ace-checkbox-2" id="ace-settings-rtl" />
                            <label class="lbl" for="ace-settings-rtl">Right To Left (rtl)</label>
                        </div>
                    </div>
                </div>
                <!--/#ace-settings-container-->
            </div>--%>
    </form>
</asp:Content>

