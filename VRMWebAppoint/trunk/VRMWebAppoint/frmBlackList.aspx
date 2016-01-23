<%@ Page Title="" Language="VB" MasterPageFile="~/ContentMasterPage.master" AutoEventWireup="false" CodeFile="frmBlackList.aspx.vb" Inherits="frmBlackList" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="Server">

    <!--Edit Styles-->

    <style type="text/css" media="screen">
        .hide_column {
            display: none;
        }
    </style>

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
                <li class="active">Blacklist</li>
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


                    <div class="row-fluid">
                        <h3 class="header smaller lighter blue">Blacklist</h3>
                        <%--    <div class="table-header">
                            View Demo
                        </div>--%>


                        <div class="row-fluid">

                            <button class="btn btn-small btn-success" id="btnAdd" name="btnAdd">
                                <i class=" icon-plus"></i>
                                Add New
                            </button>

                            <button class="btn btn-small" id="btnBack" name="btnBack">
                                <i class=" icon-undo"></i>
                                Back
                            </button>

                        </div>
                    </div>
                    <div class="space-2"></div>
                    <div id="dialog-blacklist">

                        <table class="table table-striped table-bordered table-hover" id="dt_blacklist"></table>
                    </div>
                    <div id="dialog-visitor">
                        <div class="row-fluid">
                            <table class="table table-striped table-bordered table-hover" id="dt_visitor"></table>
                        </div>
                        <div class="space-4"></div>
                        <div class="row-fluid">


                            <div class="center">
                                <button class="btn btn-info" type="button" id="btnSave" name="btnSave">
                                    <i class="icon-save bigger-110"></i>
                                    Save
                                </button>


                                &nbsp; &nbsp; &nbsp;
									<button class="btn" type="reset">
                                        <i class="icon-undo bigger-110"></i>
                                        Clear
                                    </button>
                            </div>

                        </div>
                    </div>

                    <div class="row-fluid">
                        <div class="span5">
                            <%--      <input id="txtKeepId" type="text" value="0"  style="width:50%"/>
        <input id="txtCheckId" type="text"  style="width:100%"/>--%>
                        </div>

                    </div>


                </div>

            </div>
            <br />

            <!--/.span-->
        </div>
        <!--/.row-fluid-->

        <!--/.page-content-->

        <%--<div class="ace-settings-container" id="ace-settings-container">
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
                    <input type="checkbox" class="ace-checkbox-2" id="ace-settings-rtl"  />
                    <label class="lbl" for="ace-settings-rtl">Right To Left (rtl)</label>
                </div>
            </div>
        </div>--%>
        <!--/#ace-settings-container-->
    </div>

    <!--/.main-content-->


    <div id="dialog-View" style="display: none;">

        <div class="row-fluid">
            <div class="span12">
                <!--PAGE CONTENT BEGINS-->

                <form class="form-horizontal">
                    <div class="control-group">
                        <label class="control-label" for="form-field-11">Name Field</label>

                        <div class="controls">
                            <label class="control-label" for="form-field-12">Name Field</label>
                        </div>
                    </div>

                    <div class="control-group">
                        <label class="control-label" for="form-field-21">Description Field</label>

                        <div class="controls">
                            <label class="control-label" for="form-field-22">Description Field</label>

                        </div>
                    </div>
                </form>



            </div>
        </div>
    </div>

    <div id="dialog-edit" style="display: none;">

        <div class="row-fluid">

                    <div class="span2">
                        <label class="control-label" for="lblReason">Reason</label>
                    </div>
                    <div class="span10">
                    <textarea id="txtReason" style="height: 120px; resize: none;" class="span12 limited" data-maxlength="255" maxlength="255"></textarea>
                   <%-- <span  class="help-inline color red" id="lblvalidReason" style="display: none">This field is required</span>--%>

                    </div>

        </div>
    </div>


    <script type="text/javascript">



        var oTable;
        var oTableBlacklist;
        var isAddNew = false;
        $(document).ready(function () {
            //check page show when click back
            var page = getParameterByName('page');
            if (page =='visitor'){
                clickEdit();
            }
            else if(page =='blacklist'){
                clickEndEdit();
            }else{
               $("#dialog-visitor").hide();
               $("#btnBack").hide();
            }
            

 

            //Load grid
            LoadDataBacklist();
            LoadData();


 

            //Add Click
            $("#btnAdd").click(function () {
                ReferenceGrid();
                clickEdit();
            });

            $("#btnBack").click(function () {
                ReferenceGrid();
                clickEndEdit();

            });



            $("#btnSave").click(function () {
                onConfirm(0); return false;
            });

            $("#btnDelete").click(function () {
                onConfirm(0); return false;
            });


        });

        //Get Parameter
        function getParameterByName(name) {
            name = name.replace(/[\[]/, "\\[").replace(/[\]]/, "\\]");
            var regex = new RegExp("[\\?&]" + name + "=([^&#]*)"),
                results = regex.exec(location.search);
            return results === null ? "" : decodeURIComponent(results[1].replace(/\+/g, " "));
        }

        // ==============================
        //Add or Edit 
        function clickEdit() {
            $("#btnAdd").hide();
            $("#btnBack").show();
            $("#dialog-blacklist").hide();
            $("#dialog-visitor").show();
        }
        function clickEndEdit() {
            $("#btnAdd").show();
            $("#btnBack").hide();
            $("#dialog-blacklist").show();
            $("#dialog-visitor").hide();
        }

        // Confirm 
        function onConfirmDeleteBlacklist(id) {
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
                                    onDeleteBlacklist(id);
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

        // Confirm 
        function onConfirmDeleteVisitor(id) {
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
                                    onDeleteVisitor(id);
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

        // Confirm
        function onConfirm(id) {

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




        //Load Backlist
        function LoadDataBacklist() {
            var dataurl = 'WebSevice/WebService.asmx/LoadBlackListAll';
            $.ajax({
                "type": "POST",
                "dataType": 'json',
                "contentType": "application/json; charset=utf-8",
                "url": dataurl,
                "success": PopulateGridBacklist
            });
        }

        function PopulateGridBacklist(jsondata) {
            var jsonobject = JSON.parse(jsondata.d);
            var columns = [
                            {
                                "sTitle": "No",
                                "sType": "numeric",
                                "mDataProp": "no",
                                "bUseRendered": false

                            },
                            {
                                "sTitle": "Identification Number",
                                "sType": "string",
                                "sDefaultContent": "",
                                "mDataProp": "cardno"

                            },
                            {
                                "sTitle": "Name - Last name (Thai)",
                                "sType": "string",
                                "sDefaultContent": "",
                                "mDataProp": "fullname_thai",
                            },
                            {
                                "sTitle": "Name - Last name (Eng)",
                                "sType": "string",
                                "sDefaultContent": "",
                                "mDataProp": "fullname_eng",
                            },
                            {
                                "sTitle": "Season",
                                "sType": "string",
                                "sDefaultContent": "",
                                "mDataProp": "season",
                            },

                            {
                                "sTitle": "Action",
                                "bSortable": false,
                                "fnRender": function (objblacklist) {
                                    return '<div class="hidden-phone visible-desktop action-buttons">'
                                            + '<a href="#" data-toggle="modal" class="blue"  title="View" onClick="onView(' + objblacklist.aData.id + ');">'
                                            + '<span class="blue"><i class="icon-zoom-in bigger-130"></i></span>'
                                            + '</a>'
                                            + '&nbsp;'
                                            + '<a href="#"  class="Green"  title="Edit" onClick="onEdit(' + objblacklist.aData.id + ');">'
                                            + '<span class="green"><i class="icon-pencil bigger-130"></i></span>'
                                            + '</a>'
                                            + '&nbsp;'
                                            + '<a href="#"  class="Red"  title="Delete" onclick="onConfirmDeleteBlacklist(' + objblacklist.aData.id + ');" >'
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
                                            + '						<a href="#"  class="tooltip-info" data-rel="tooltip" title="View" onClick="onView(' + objblacklist.aData.id + ');">'
                                            + '							<span class="blue">'
                                            + '								<i class="icon-zoom-in bigger-120"></i>'
                                            + '							</span>'
                                            + '						</a>'
                                            + '					</li>'
                                            + ''
                                            + '					<li>'
                                            + '						<a href="#"  style="display: none;" class="tooltip-success" data-rel="tooltip" title="Edit" onClick="onEdit(' + objblacklist.aData.id + ');">'
                                            + '							<span class="green">'
                                            + '								<i class="icon-edit bigger-120"></i>'
                                            + '							</span>'
                                            + '						</a>'
                                            + '					</li>'
                                            + ''
                                            + '					<li>'
                                            + '						<a href="#"  class="tooltip-error" data-rel="tooltip" title="Delete" onclick="onConfirmDeleteBlacklist(' + objblacklist.aData.id + ');">'
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

            oTableBlacklist = $('#dt_blacklist').dataTable({
                "aaData": jsonobject,
                "bAutoWidth": false,
                "aoColumnDefs": [
                { "sWidth": "10%", "aTargets": [0] },
                { "sWidth": "15%", "aTargets": [1] },
                { "sWidth": "20%", "aTargets": [2] },
                { "sWidth": "20%", "aTargets": [3] },
                { "sWidth": "25%", "aTargets": [4] },
                { "sWidth": "10%", "sClass": "aligncenter", "aTargets": [5] }
                ],
                "aoColumns": columns,
                "bDestroy": true
            });


        }
        //Load BacklistVisitor
        function LoadData() {
            var dataurl = 'WebSevice/WebService.asmx/LoadVisitorAll';
            $.ajax({
                "type": "POST",
                "dataType": 'json',
                "contentType": "application/json; charset=utf-8",
                "url": dataurl,
                "success": PopulateGrid
            });
        }

        function PopulateGrid(jsondata) {
            var jsonobject = JSON.parse(jsondata.d);
            var columns = [{
                "sTitle": '<label><input type="checkbox" id="checkall" name="checkall" class="select_rows"  data-tableid="dt_visitor" onclick=CheckSelectAll(this); value="0"  /><span class="lbl"></span> Select All</label>',
                "bSortable": false,
                "fnRender": function (obj) {
                    // return '<label><input type="checkbox" id="row_sel" name="row_sel" class="select_rows" onclick=KeepID($(this).val(),this.checked); value="0" /><span class="lbl"></span></label>';

                    return '<label><input type="checkbox" id="' + obj.aData.id + '" name="' + obj.aData.id + '" class="select_rows" onclick=KeepID($(this).val(),this.checked); value=' + obj.aData.id + '  /><span class="lbl"></span></label>';
                },
                "sDefaultContent": "",
                "bUseRendered": true
            },

                            {
                                "sTitle": "No",
                                "sType": "numeric",
                                "mDataProp": "no",
                                "bUseRendered": false

                            },
                            {
                                "sTitle": "Identification Number",
                                "sType": "string",
                                "sDefaultContent": "",
                                "mDataProp": "cardno"

                            },
                            {
                                "sTitle": "Name - Last name (Thai)",
                                "sType": "string",
                                "sDefaultContent": "",
                                "mDataProp": "fullname_thai",
                            },
                            {
                                "sTitle": "Name - Last name (Eng)",
                                "sType": "string",
                                "sDefaultContent": "",
                                "mDataProp": "fullname_eng",
                            },
                            {
                                "sTitle": "Reason",
                                "bSortable": false,
                                "fnRender": function (obj) {
                                    // return '<label><input type="checkbox" id="row_sel" name="row_sel" class="select_rows" onclick=KeepID($(this).val(),this.checked); value="0" /><span class="lbl"></span></label>';

                                    return '<input id=' + obj.aData.id + ' type="text"   />';
                                },
                                "sDefaultContent": "",
                                "bUseRendered": true
                            },
                            //{
                            //    "sTitle": "Address",
                            //    "sType": "string",
                            //    "sDefaultContent": "",
                            //    "mDataProp": "address",
                            //},
                            //{
                            //    "sTitle": "Blaklist Status",
                            //    "sType": "string",
                            //    "sDefaultContent": "",
                            //    "mDataProp": "BlaklistStatus",
                            //    "sClass": "hide_column"

                            //},

                            {
                                "sTitle": "Action",
                                "bSortable": false,
                                "fnRender": function (obj) {
                                    return '<div class="hidden-phone visible-desktop action-buttons">'
                                            + '<a href="#" data-toggle="modal" class="blue"  title="View" onClick="onView_visitor(' + obj.aData.id + ');">'
                                            + '<span class="blue"><i class="icon-zoom-in bigger-130"></i></span>'
                                            + '</a>'
                                            + '&nbsp;'
                                            + '<a href="#" style="display: none;"  class="Green"  title="Edit" onClick="onEdit(' + obj.aData.id + ');">'
                                            + '<span class="green"><i class="icon-pencil bigger-130"></i></span>'
                                            + '</a>'
                                            + '&nbsp;'
                                            + '<a href="#" style="display: none;"  class="Red"  title="Delete" onclick="onConfirmDeleteVisitor(' + obj.aData.id + ');" >'
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
                                            + '						<a href="#"  class="tooltip-info" data-rel="tooltip" title="View" onClick="onView_visitor(' + obj.aData.id + ');">'
                                            + '							<span class="blue">'
                                            + '								<i class="icon-zoom-in bigger-120"></i>'
                                            + '							</span>'
                                            + '						</a>'
                                            + '					</li>'
                                            + ''
                                            + '					<li>'
                                            + '						<a href="#" style="display: none;"   class="tooltip-success" data-rel="tooltip" title="Edit" onClick="onEdit(' + obj.aData.id + ');">'
                                            + '							<span class="green">'
                                            + '								<i class="icon-edit bigger-120"></i>'
                                            + '							</span>'
                                            + '						</a>'
                                            + '					</li>'
                                            + ''
                                            + '					<li>'
                                            + '						<a href="#" style="display: none;"  class="tooltip-error" data-rel="tooltip" title="Delete" onclick="onConfirmDeleteVisitor(' + obj.aData.id + ');">'
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

            oTable = $('#dt_visitor').dataTable({
                "aaData": jsonobject,
                "bAutoWidth": false,
                "aoColumnDefs": [
                { "sWidth": "10%", "sClass": "aligncenter", "aTargets": [0] },
                { "sWidth": "5%", "aTargets": [1] },
                { "sWidth": "15%", "aTargets": [2] },
                { "sWidth": "20%", "aTargets": [3] },
                { "sWidth": "20%", "aTargets": [4] },
                { "sWidth": "20%", "aTargets": [5] },
                { "sWidth": "10%", "sClass": "aligncenter", "aTargets": [6] }
                ],
                "aoColumns": columns,
                "bDestroy": true,
                "fnDrawCallback": function () {
                    //  alert($("#checkall").val());
                    //var strCheckAll = $("input[name=checkall]:checked").length;
                    //if (strCheckAll == 1) {
                    //    $("#checkall").prop("checked", false);
                    //}

                }

            });



        }

        //Re
        function ReferenceGrid() {
            LoadData();
            LoadDataBacklist();
        }

        //คลิก checkbox ที่ Header
        function CheckSelectAll(e) {

            if (e.checked) { // check select status
                $('.select_rows').each(function () { //loop through each checkbox
                    this.checked = true;  //select all checkboxes with class "checkbox1" 
                    // KeepID($(this).val(), this.checked);
                });
            } else {
                $('.select_rows').each(function () { //loop through each checkbox
                    this.checked = false; //deselect all checkboxes with class "checkbox1"  
                    // KeepID($(this).val(), this.checked);
                });
            }
        }

        //เก็บ ID ที่เลือกเก็ยไว้ใน Textbook  (รุปแบบคือ:1#false,2#true,3#false)
        function KeepID(value, check) {
            var strId = $("#txtKeepId").val();
            if (strId.indexOf(value + '#') == -1) {
                $("#txtKeepId").val(strId + ',' + value + '#' + check);
            } else {
                if (check == false) {
                    $("#txtKeepId").val(strId.replace(',' + value + '#' + 'true', ',' + value + '#' + 'false'));
                } else {
                    $("#txtKeepId").val(strId.replace(',' + value + '#' + 'false', ',' + value + '#' + 'true'));
                }

            }

        }

        // fucntion ลบข้อมูล
        function onDelete(RowID) {

            var param = "{'RowID':" + JSON.stringify(RowID) + "}";
            $.ajax({
                type: "POST",
                url: "WebSevice/WebService.asmx/DeleteDemo",
                data: param,
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: onSuccess,
                error: onFailed
            });


        }
        function onSuccess(result) {

            if (result.d == true) {
                ReferenceGrid();
                clickEndEdit();
                onAlert("Save Complete");
            } else {
                onAlert("Save Fail");
            }

        }

        function onFailed() {
            onAlert("Save Fail");
        }


        function onSave() {

            //Get value  in grid
            var struserblacklist = new Array;
            var oTable = $('#dt_visitor').dataTable();
            var strCheckId = new Array;
            $("input[type=checkbox]:checked", oTable.fnGetNodes()).each(function () {
                $input = $(this);
                strCheckId.push($input.attr("id"));
            });

            for (var i = 0; i < strCheckId.length; i++) {
                $("input[type=text]", oTable.fnGetNodes()).each(function () {
                    $input2 = $(this);
                    if (strCheckId[i] == $input2.attr("id")) {
                        //alert(strCheckId[i]);
                        //alert($input2.val());
                        struserblacklist.push(strCheckId[i] + '#' + $input2.val());

                    }
                });

            }


            var userid = $('#' + '<%=Master.FindControl("lblUserID").ClientID%>').text();

            var param = "{'strID':" + JSON.stringify(struserblacklist)
                       + ",'userid':" + JSON.stringify(userid) + "}";
            //var param = "{'strID':" + strTemp + "}";
            $.ajax({
                type: "POST",
                url: "WebSevice/WebService.asmx/SaveBlackList",
                data: param,
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: onSuccess,
                error: onFailed
            });

            //alert(strTemp.replace('#',''));

            //onAlert("Save Call Function");
        }

        function onSaveReason(id) {
            var userid = $('#' + '<%=Master.FindControl("lblUserID").ClientID%>').text();
            var reson = $("#txtReason").val();

            var param = "{'id':" + JSON.stringify(id)
                       + ",'reason':" + JSON.stringify(reson)
                       + ",'userid':" + JSON.stringify(userid) + "}";
            //var param = "{'strID':" + strTemp + "}";
            $.ajax({
                type: "POST",
                url: "WebSevice/WebService.asmx/UpdateReason",
                data: param,
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: onSuccess,
                error: onFailed
            });

            //alert(strTemp.replace('#',''));

            //onAlert("Save Call Function");
        }



        function onView(id) {
                window.location.href = "frmProfileView.aspx?page=blacklist&ext=0&id=" + id;
       }
        function onView_visitor(id) {
                window.location.href = "frmProfileView.aspx?page=visitor&ext=0&id=" + id;
       }

        function onEdit(id) {
            var param = "{'id':" + JSON.stringify(id) + "}";
            $.ajax({
                type: "POST",
                url: "WebSevice/WebService.asmx/GetBlackListBy",
                data: param,
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: function (data) {
                    var strvalue = JSON.parse(data.d);
                    if (strvalue.length == 1) {
                        $("#txtReason").val(strvalue[0].blacklist_reason);
                    } else {
                        $("#txtReason").val("");
                    }
                }
            });

            $("#dialog-edit").dialog({
                autoOpen: false,
                resizable: false,
                width: "500px",
                modal: true,
                buttons: {
                    "Save": function () {
                        $(this).dialog("close");
                        onSaveReason(id);
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

            $("#dialog-edit").dialog("option", "title", "Edit").dialog("open");

        }

        function onDeleteBlacklist(id) {

            var userid = $('#' + '<%=Master.FindControl("lblUserID").ClientID%>').text();

                var param = "{'id':" + JSON.stringify(id)
                           + ",'userid':" + JSON.stringify(userid) + "}";
                $.ajax({
                    type: "POST",
                    url: "WebSevice/WebService.asmx/DeleteBlackList",
                    data: param,
                    contentType: "application/json; charset=utf-8",
                    dataType: "json",
                    success: onDeleteSuccess,
                    error: onDeleteFailed
                });

                //alert(strTemp.replace('#',''));

                //onAlert("Save Call Function");
        }

        function onDeleteVisitor(id) {

            var param = "{'id':" + JSON.stringify(id) + "}";


            $.ajax({
                type: "POST",
                url: "WebSevice/WebService.asmx/DeleteVisitor",
                data: param,
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: onDeleteSuccess,
                error: onDeleteFailed
            });

            //alert(strTemp.replace('#',''));

            //onAlert("Save Call Function");
        }


            function onDeleteSuccess(result) {

                if (result.d == true) {
                    onAlert("Delete Complete");
                    LoadDataBacklist();
                    LoadData();
                } else {
                    onAlert("Delete Fail");
                }

            }

            function onDeleteFailed() {
                onAlert("Delete Fail");
            }






    </script>


</asp:Content>

