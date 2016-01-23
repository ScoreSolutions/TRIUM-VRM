<%@ Page Title="" Language="VB" MasterPageFile="~/ContentMasterPage.master" AutoEventWireup="false" CodeFile="frmUser.aspx.vb" Inherits="frmUser" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="Server">
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
                <li class="active">User</li>
            </ul>

        </div>

        <div class="page-content">


            <div class="row-fluid">
                <div class="span12">
                    <!--PAGE CONTENT BEGINS-->
                    <h3 class="header smaller lighter blue">User</h3>

                    <div class="row-fluid">
                        <div class="span12" id="divbtnAdd">
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
                    <div id="dialog-grid">
                        <div class="row-fluid">
                            <div class="span12">
                                <table class="table table-striped table-bordered table-hover" id="dt_out"></table>
                            </div>
                        </div>
                    </div>




                    <div id="dialog-edit">
                        <div class="row-fluid" style="display: none">
                            <div class="span2">
                                <label class="control-label" id="lblImage">User Image</label>
                            </div>
                            <div class="span7">
                                <div class="row-fluid">
                                    <div class="span4">
                                        <a href="images/No_image.gif" id="aimg" style="display: none;"></a>
                                        <%--				<a href="images/No_image.gif" rel="prettyPhoto"   id="aimg"><img   id="img" src="images/No_image.gif"  style="height: 150px; width: 200px;" /></a>--%>
                                        <img id="img" src="images/No_image.gif" style="height: 150px; width: 200px; cursor: pointer;" />
                                        <div id="dialog-image" style="display: none">
                                            <img id="imgPopup" src="images/No_image.gif" style="height: 350px; width: 500px;" />
                                        </div>


                                        <div id="base" style="display: none"></div>
                                        <div id="basepath" style="display: none"></div>
                                        <div id="basename"></div>

                                        <div class="space-2"></div>
                                        <span class="btn btn-default btn-mini btn-file">Browse&hellip; 
                                    <input type='file' id="roomimagefile" class="ace-file-input" />
                                        </span>
                                        <button class="btn btn-danger btn-mini" id="btnClearImage">
                                            Clear
                                        </button>

                                    </div>
                                    <div class="span4">
                                        <span class="help-inline" id="lblvalidfiletype">file type : gif,png,jpg,jpeg</span>
                                        <span class="help-inline" id="lblvalidfilesize">file type : size less than 1MB</span>
                                    </div>
                                    <div class="span4"></div>
                                </div>

                            </div>
                        </div>
                        <div class="space-2"></div>
                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" id="lblEmployee_code">Employee Code</label>
                            </div>
                            <div class="span10">
                                <input type="text" id="txtEmployee_code" class="limited" data-maxlength="50" maxlength="50" >
                                <span class="help-inline color red" id="lblvalidEmployee_code" style="display: none">This field is required</span>
                            </div>
                        </div>

                        <div class="space-2"></div>
                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" for="lblRoomType">Prefix Name</label>
                            </div>
                            <div class="span10">
                                <select class="chzn-select" id="cbPrefix" data-placeholder="Choose a Prefix..."></select>
                                <span class="help-inline color red" id="lblvalidms_prefix_id" style="display: none">This field is required</span>
                            </div>
                        </div>
                        <div class="space-2"></div>





                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" id="lblName">Name</label>
                            </div>
                            <div class="span10">
                                <input type="text" id="txtName" class="limited" data-maxlength="50" maxlength="50" >
                                <span class="help-inline color red" id="lblvalidName" style="display: none">This field is required</span>
                            </div>
                        </div>



                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" id="lblSurname">Surname</label>
                            </div>
                            <div class="span10">
                                <input type="text" id="txtSurname" class="limited" data-maxlength="50" maxlength="50" >
                                <span class="help-inline color red" id="lblvalidSurname" style="display: none">This field is required</span>
                            </div>
                        </div>
                        <div class="space-2"></div>
                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" for="lblDepartment">Department</label>
                            </div>
                            <div class="span10">
                                <select class="chzn-select" id="cbDepartment" data-placeholder="Choose a Department..."></select>
                                <span class="help-inline color red" id="lblvalidms_department_id" style="display: none">This field is required</span>
                            </div>
                        </div>
                        <div class="space-2"></div>
                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" for="lblPosition">Position</label>
                            </div>
                            <div class="span10">
                                <select class="chzn-select" id="cbPosition" data-placeholder="Choose a Position..."></select>
                                <span class="help-inline color red" id="lblvalidms_position_id" style="display: none">This field is required</span>
                            </div>
                        </div>
                        <div class="space-2"></div>
                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" id="lblUserActive">Active</label>
                            </div>
                            <div class="span10">
                                <div class="controls">
                                    <label class="inline">
                                        <input name="ckbActive" type="checkbox" id="ckbActive" />
                                        <span class="lbl">&nbsp;</span>
                                    </label>
                                </div>
                            </div>
                        </div>

                        <div class="row-fluid">
                            <h3 class="header smaller lighter blue">Username and Password</h3>
                        </div>
                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" id="lblUsername">Username</label>
                            </div>
                            <div class="span10">
                                <input type="text" id="txtUsername" class="limited" data-maxlength="50" maxlength="50" >
                                <span class="help-inline color red" id="lblvalidUsername" style="display: none">This field is required</span>
                            </div>
                        </div>

                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" id="lblPassword">Password</label>
                            </div>
                            <div class="span10">
                                <input type="password" id="txtPassword" class="limited" data-maxlength="50" maxlength="50" >
                                <span class="help-inline color red" id="lblvalidPassword" style="display: none">This field is required</span>

                            </div>
                        </div>

                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" id="lblConfirmPassword">Confirm Password</label>
                            </div>
                            <div class="span10">
                                <input type="password" id="txtConfirmPassword" class="limited" data-maxlength="50" maxlength="50" >
                                <span class="help-inline color red" id="lblvalidConfrimPassword" style="display: none">This field is required</span>
                                <span class="help-inline color red" id="lblvalidComprePassword" style="display: none">Password != Confirm Password</span>

                            </div>
                        </div>









                        <div class="row-fluid">
                            <div class="span2">
                            </div>
                            <div class="span10">
                                <button class="btn btn-primary" id="btnSave" name="btnSave">
                                    <i class="icon-edit  bigger-110"></i>
                                    Save
                       
                                </button>
                                <button class="btn" type="reset" id="btnClear" name="btnClear">
                                    <i class="icon-undo bigger-110"></i>
                                    Clear
                                </button>
                            </div>
                        </div>
                    </div>

                </div>

            </div>


        </div>
    </div>

    <%--    <div class="ace-settings-container" id="ace-settings-container">
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
        </div>--%>
    <!--/#ace-settings-container-->

    <%--    <div class="row-fluid">
        <div class="span12" id="inputimagefile">
         <input type="file" />  
        </div>
    </div>--%>


    <%-- //Keep Path input file--%>
    <input id="HiddenId" type="hidden" />

    <%--    <style type="text/css" media="all">

	.my_class {
				word-wrap: break-word;
			}
    </style>--%>


    <script type="text/javascript">
        //Open page
        $(document).ready(function () {

            //Load Room
            var oTable;
            var isAddNew = false;
            LoadData();

            //Add Click
            $("#btnAdd").click(function () {
                onEdit(0);
                clickEdit();

                //SaveToDisk("D:\Kiosk_File\file0name.jpg", 'file0name2.jpg');
                //Spinner

                //return false;
            });

            $("#btnBack").click(function () {
                onEdit(0);
                clickEndEdit();

            });

            $("#btnClearImage").click(function () {
                $("roomimagefile").val("");
                clearImage();
            });

            $("#btnSave").click(function () {
                var ret = onValid();
                if (ret == true) {
                    onConfirmSave();
                }

            });

            $("#btnClear").click(function () {
                clearInput();
            });


            //Spinner
            //$('#txtAttendance').ace_spinner({ value: 0, min: 0, max: 10000, step: 1, icon_up: 'icon-caret-up', icon_down: 'icon-caret-down' });

            //Input file

            $("#roomimagefile").change(function () {
                readImage(this);
            });

            $("#img").click(function () {
                imagePopup();
            });

            //Populate Select
            //populateSelect(0);

            //Hide div or other
            $("#dialog-edit").hide();
            $("#btnBack").hide();



        });




        //Call
        function LoadData() {
            var dataurl = 'WebSevice/WebService.asmx/LoadUserAll';
            $.ajax({
                "type": "POST",
                "dataType": 'json',
                "contentType": "application/json; charset=utf-8",
                "url": dataurl,
                "success": PopulateGrid
            });
        }

        //Populate Grid
        function PopulateGrid(jsondata) {
            var jsonobject = JSON.parse(jsondata.d);
            var columns = [{
                "sTitle": "No",
                "sType": "numeric",
                "mDataProp": "no",
                "bUseRendered": false

            },
                            {
                                "sTitle": "Employee Code",
                                "sType": "string",
                                "sDefaultContent": "",
                                "mDataProp": "employee_code"

                            },
                            {
                                "sTitle": "Name - Surname",
                                "sType": "string",
                                "sDefaultContent": "",
                                "mDataProp": "fullname"

                            },
                            {
                                "sTitle": "Department",
                                "sType": "string",
                                "sDefaultContent": "",
                                "mDataProp": "department_name"

                            },
                           {
                               "sTitle": "Position",
                               "sType": "string",
                               "sDefaultContent": "",
                               "mDataProp": "position_name"

                           },

                            //{
                            //    "sTitle": "Room Description",
                            //    "sType": "string",
                            //    "sDefaultContent": "",
                            //    "mDataProp": "room_desc"
                            //   // "fnRender": function (obj) {
                            //    //   // return '<div style="word-wrap: break-word; width: 300px" id="lblRoomDescBild">999999999999999999999999999999999999999999999999991111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111</div>';
                            //    //    // wordWrap(str, 40)

                            //    //    //return wordWrap(obj.aData.Room_desc , 10);
                            //    //    return '<div class="my_class" id="lblRoomDescBild">' + obj.aData.room_desc + '</div>';
                            //   // }

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
                                            + '<a href="#"  class="Green"  title="Edit" onClick="onEdit(' + obj.aData.id + ');clickEdit();">'
                                            + '<span class="green"><i class="icon-pencil bigger-130"></i></span>'
                                            + '</a>'
                                            + '&nbsp;'
                                            + '<a href="#"  class="Red"  title="Delete" onclick="onConfirmDelete(' + obj.aData.id + ');" >'
                                            + '<span class="red"><i class="icon-trash bigger-130"></i></span>'
                                            + '</a>'
                                            + '</div>'
                                            + '<div class="hidden-desktop visible-phone">'
                                            + '			<div class="inline position-relative">'
                                            + '				<button class="btn btn-minier btn-primary dropdown-toggle" data-toggle="dropdown">'
                                            + '					<i class="icon-cog icon-only bigger-110"></i>'
                                            + '				</button>'
                                            + '				<ul class="dropdown-menu dropdown-icon-only dropdown-yellow pull-right dropdown-caret dropdown-close">'
                                            + ''
                                            + '					<li>'
                                            + '						<a href="#"   class="tooltip-success" data-rel="tooltip" title="Edit" onClick="onEdit(' + obj.aData.id + ');clickEdit();">'
                                            + '							<span class="green">'
                                            + '								<i class="icon-edit bigger-120"></i>'
                                            + '							</span>'
                                            + '						</a>'
                                            + '					</li>'
                                            + '					<li>'
                                            + '						<a href="#"  class="tooltip-error" data-rel="tooltip" title="Delete" onclick="onConfirmDelete(' + obj.aData.id + ');">'
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
                "aaData": jsonobject,
                "bAutoWidth": false,
                "aoColumnDefs": [
                { "sWidth": "10%", "aTargets": [0] },
                { "sWidth": "15%", "aTargets": [1] },
                { "sWidth": "25%", "aTargets": [2] },
                { "sWidth": "15%", "aTargets": [3] },
                { "sWidth": "15%", "aTargets": [4] },
                { "sWidth": "10%", "aTargets": [5] },
                { "sWidth": "10%", "aTargets": [6] }
                ],
                "aoColumns": columns,
                "bDestroy": true,
            });


        }

        //Add or Edit 
        function clickEdit() {
            $("#btnAdd").hide();
            $("#btnBack").show();
            $("#dialog-grid").hide();
            $("#dialog-edit").show();
        }
        function clickEndEdit() {
            $("#btnAdd").show();
            $("#btnBack").hide();
            $("#dialog-grid").show();
            $("#dialog-edit").hide();
        }
        function onEdit(id) {
            onValidHide();
            $("#HiddenId").val(id);
            var param = "{'id':" + JSON.stringify(id) + "}";

            $.ajax({
                type: "POST",
                url: "WebSevice/WebService.asmx/GetUserById",
                data: param,
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: function (data) {
                    var strvalue = JSON.parse(data.d);

                    if (strvalue.length == 1) {
                        $("#HiddenId").val(strvalue[0].id);
                        $("#txtEmployee_code").val(strvalue[0].employee_code);
                        $("#txtName").val(strvalue[0].name_eng);
                        $("#txtSurname").val(strvalue[0].surname_eng);
                        $("#txtUsername").val(strvalue[0].username);
                        $("#txtPassword").val(strvalue[0].password);
                        $("#txtConfirmPassword").val(strvalue[0].password);
                        if (strvalue[0].room_image_name != '') {
                            $("#img").attr("src", strvalue[0].room_image);
                            $("#imgPopup").attr("src", strvalue[0].room_image);
                            $("#base").text(strvalue[0].room_image_base64);
                            $("#basepath").text(strvalue[0].room_image_path);
                            $("#basename").text(strvalue[0].room_image_name + '.' + strvalue[0].room_image_type);
                            $("#img").attr("alt", strvalue[0].room_image_name + '.' + strvalue[0].room_image_type);
                            $("#aimg").attr("href", strvalue[0].room_image);

                        } else {
                            clearImage();
                        }

                        populateSelect(strvalue[0].id);
                        if (strvalue[0].active_status == "Y") {
                            $("#ckbActive").prop("checked", true);
                        } else {
                            $("#ckbActive").prop("checked", false);
                        }
                    } else {
                        $("#HiddenId").val(0);
                        $("#txtEmployee_code").val("");
                        $("#txtName").val("");
                        $("#txtSurname").val("");
                        $("#txtUsername").val("");
                        clearImage();
                        populateSelect(0);
                        $("#ckbActive").prop("checked", false);
                    }
                },
                error: function (data) {
                }
            });

            //$("#dialog-edit").dialog({
            //    autoOpen: false,
            //    resizable: false,
            //    width: "600px",
            //    modal: true,
            //    buttons: {
            //        "Save": function () {

            //            var pathvalue = $('#HiddenPathInputFile').val();
            //            alert(pathvalue);
            //            var ret = onValid();
            //            if (ret == true) {
            //                onSave(id);
            //            }

            //        },
            //        "Close": function () {
            //            $(this).dialog("close");
            //        }

            //    },
            //    show: {
            //        effect: 'size',
            //        duration: 500
            //    },
            //    hide: {
            //        effect: 'size',
            //        duration: 500
            //    }
            //});

            //var titledialog;
            //if (id == 0) {
            //    titledialog = "Add New";
            //} else {
            //    titledialog = "Edit";
            //}

            //$("#dialog-edit").dialog("option", "title", titledialog).dialog("open");

        }



        //Save Room
        function onSave() {
            var id = $("#HiddenId").val();
            var userid = $('#' + '<%=Master.FindControl("lblUserID").ClientID%>').text();
            var ms_prefix_id = $('#cbPrefix').val();
            var employee_code = $("#txtEmployee_code").val();
            var name_eng = $("#txtName").val();
            var surname_eng = $("#txtSurname").val();
            var name_thai = "";
            var surname_thai = "";
            var ms_position_id = $("#cbPosition").val();
            var ms_department_id = $("#cbDepartment").val();
            var username = $("#txtUsername").val();
            var password = $("#txtPassword").val();
            var room_active = $('input[name="ckbActive"]:checked').length;
            var strimagebase64 = "";// $("#base").text();
            var strimagename = "";//$("#basename").text();
            var strimagepath = "";// $("#basepath").text();

            if (room_active == 0) {
                room_active = "N"
            } else {
                room_active = "Y"
            }


            var param = "{'id':" + JSON.stringify(id)
                + ",'ms_prefix_id':" + JSON.stringify(ms_prefix_id)
                + ",'employee_code':" + JSON.stringify(employee_code)
                + ",'name_thai':" + JSON.stringify(name_thai)
                + ",'name_eng':" + JSON.stringify(name_eng)
                + ",'surname_thai':" + JSON.stringify(surname_thai)
                + ",'surname_eng':" + JSON.stringify(surname_eng)
                + ",'ms_department_id':" + JSON.stringify(ms_department_id)
                + ",'ms_position_id':" + JSON.stringify(ms_position_id)
                + ",'username':" + JSON.stringify(username)
                + ",'password':" + JSON.stringify(password)
                + ",'strimagebase64':" + JSON.stringify(strimagebase64)
                + ",'strimagename':" + JSON.stringify(strimagename)
                + ",'strimagepath':" + JSON.stringify(strimagepath)
                + ",'userid':" + JSON.stringify(userid)
                + ",'active':" + JSON.stringify(room_active) + "}";


            $.ajax({
                type: "POST",
                url: "WebSevice/WebService.asmx/SaveUser",
                data: param,
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: onUserSuccess,
                error: onFailed
            });
        }
        //Delete Room
        function onDelete(id) {
            var param = "{'id':" + JSON.stringify(id) + "}";

            $.ajax({
                type: "POST",
                url: "WebSevice/WebService.asmx/DeleteUser",
                data: param,
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: onDeleteSuccess,
                error: onDeleteFailed
            });
        }

        //Confirm delete Room
        function onConfirmDelete(id) {

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
                                    onDelete(id);

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

        //Confirm save Room
        function onConfirmSave() {

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

        //Room  Alert  True
        function onUserSuccess(result) {
            if (result.d == "YES") {
                onAlert("Save Complete");
                LoadData();
                clearInput();
                clickEndEdit();
            } else {
                if (result.d == "DUPLICATEUSERNAME") {
                    onAlert("Username already exists. Please modify username");
                    LoadData();
                }
                else if (result.d == "DUPLICATE") {
                    onAlert("Name and suranme already exists. Please modify Name or suranme");
                    LoadData();
                }
                else if (result.d == "DUPLICATEEMPLOYEECODE") {
                    onAlert("Employee code already exists. Please modify employee code");
                    LoadData();
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
                LoadData();

            } else {
                onAlert("Delete Fail");
            }

        }

        //Alert Delete when false
        function onDeleteFailed() {
            onAlert("Delete Fail");
        }


        // Alert Box
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



        //Hide Valid
        function onValidHide() {
            $("#lblvalidEmployee_code").hide();
            $("#lblvalidms_prefix_id").hide();
            $("#lblvalidName").hide();
            $("#lblvalidSurname").hide();
            $("#lblvalidms_department_id").hide();
            $("#lblvalidms_position_id").hide();
            $("#lblvalidUsername").hide();
            $("#lblvalidPassword").hide();
            $("#lblvalidConfrimPassword").hide();
            $("#lblvalidComprePassword").hide();
 
        }
        //Check Valid
        function onValid() {

            var isValid;
            isValid = true;
            var ms_prefix_id = $('#cbPrefix').val();
            var employee_code = $("#txtEmployee_code").val();
            var name_eng = $("#txtName").val();
            var surname_eng = $("#txtSurname").val();
            var name_thai = "";
            var surname_thai = "";
            var ms_position_id = $("#cbPosition").val();
            var ms_department_id = $("#cbDepartment").val();
            var username = $("#txtUsername").val();
            var password = $("#txtPassword").val();
            var passwordconfirm = $("#txtConfirmPassword").val();
            var room_active = $('input[name="ckbActive"]:checked').length;
            var strimagebase64 = $("#base").text();
            var strimagepath = $("#basename").text();


            if (ms_prefix_id == '') {
                $("#lblvalidms_prefix_id").show();
                isValid = false;
            } else {
                $("#lblvalidms_prefix_id").hide();
            }
           
            if (employee_code == '') {
                $("#lblvalidEmployee_code").show();
                isValid = false;
            } else {
                $("#lblvalidEmployee_code").hide();

            }
            if (name_eng == '') {
                $("#lblvalidName").show();
                isValid = false;
            } else {
                $("#lblvalidName").hide();

            }

            if (surname_eng == '') {
                $("#lblvalidSurname").show();
                isValid = false;
            } else {
                $("#lblvalidSurname").hide();

            }

            if (ms_department_id == '') {
                $("#lblvalidms_department_id").show();
                isValid = false;
            } else {
                $("#lblvalidms_department_id").hide();
            }

            if (ms_position_id == '') {
                $("#lblvalidms_position_id").show();
                isValid = false;
            } else {
                $("#lblvalidms_position_id").hide();
            }

            if (username == '') {
                $("#lblvalidUsername").show();
                isValid = false;
            } else {
                $("#lblvalidUsername").hide();
            }

            if (password == '') {
                $("#lblvalidPassword").show();
                isValid = false;
            } else {
                $("#lblvalidPassword").hide();
            }

            if (passwordconfirm == '') {
                $("#lblvalidConfrimPassword").show();
                isValid = false;
            } else {
                $("#lblvalidConfrimPassword").hide();
            }

            if (password != passwordconfirm) {
                $("#lblvalidComprePassword").show();
                isValid = false;
            } else {
                $("#lblvalidComprePassword").hide();
            }
            




            return isValid;
        }
        //Read image file
        function readImage(input) {
            if (input.files && input.files[0]) {
                var FR = new FileReader();
                FR.onload = function (e) {
                    var binaryString = [];


                    //$('#basename').text($('input[type=file]').val());
                    // $('#basename').text(e.target.result);
                    var file = input.files[0];
                    var fileName = file.name;
                    var fileExt = fileName.split('.').pop().toLowerCase();

                    var filesize = file.size;

                    if ($.inArray(fileExt, ['gif', 'png', 'jpg', 'jpeg']) == -1) {
                        onAlert("Please input image type gif,png,jpg,jpeg");
                    } else if ((filesize / 1024) > 1000) { //1Mb
                        onAlert("Please input image size less than 1MB");
                    } else {
                        $("#img").attr("src", e.target.result);
                        $("#imgPopup").attr("src", e.target.result);
                        binaryString = e.target.result;
                        binaryString = binaryString.split(',');
                        $("#base").text(binaryString[1]);
                        $("#basepath").text($('input[type=file]').val());
                        //$("#basepath").text(file.val().replace(/(c:\\)*fakepath/i, ''));

                        $('#basename').text(fileName);
                        $("#img").attr("alt", fileName)
                        $("#aimg").attr("href", e.target.result);
                    }





                };
                FR.readAsDataURL(input.files[0]);
            }
        }
        //Image popup
        function imagePopup() {
            $("#dialog-image").dialog({
                autoOpen: false,
                resizable: false,
                width: "500px",
                modal: true
            });

            var titledialog = "Image";


            $("#dialog-image").dialog("option", "title", titledialog).dialog("open");
        }

        //Clear image
        function clearImage() {
            $("#img").attr("src", "images/No_image.gif");
            $("#imgPopup").attr("src", "images/No_image.gif");
            $("#aimg").attr("img", "")
            $("#aimg").attr("href", "images/No_image.gif");
            $("#base").text("");
            $("#basepath").text("");
            $("#basename").text("");
        }

        function clearInput() {
            $("#txtEmployee_code").val("");
            $("#txtName").val("");
            $("#txtSurname").val("");
            $("#txtUsername").val("");
            $("#txtPassword").val("");
            $("#txtConfirmPassword").val("");
            clearImage();
            populateSelect(0);
            $("#ckbActive").prop("checked", false);
        }
        //Populate Option By Room ID
        function populateSelect(user_id) {
            var strselect;
            var param = "{'user_id':" + JSON.stringify(user_id) + "}";


            //Populate Check Select
            $select = $("#cbPrefix");
            $.ajax({
                type: "POST",
                url: 'WebSevice/WebService.asmx/LoadPrefixBy',
                data: param,
                dataType: 'JSON',
                contentType: "application/json; charset=utf-8",
                success: function (data) {
                    var jsonobject = JSON.parse(data.d);
                    //clear 
                    $select.html('');
                    $select.append('<option value="">Choose a Prefix</option>');
                    //append a select option
                    $.each(jsonobject, function (key, val) {
                        strselect = '';
                        if (val.selected != "") {
                            strselect = ' selected="' + val.selected + '"';
                        }

                        $select.append('<option value="' + val.id + '" ' + strselect + '>' + val.prefix_eng + '</option>');
                        $select.trigger("liszt:updated");//update select option
                    })
                }
            });

            $selectPosition = $("#cbPosition");
            $.ajax({
                type: "POST",
                url: 'WebSevice/WebService.asmx/LoadPositionBy',
                data: param,
                dataType: 'JSON',
                contentType: "application/json; charset=utf-8",
                success: function (data) {
                    var jsonobject = JSON.parse(data.d);
                    //clear 
                    $selectPosition.html('');
                    $selectPosition.append('<option value="">Choose a Position</option>');
                    //append a select option
                    $.each(jsonobject, function (key, val) {
                        strselect = '';
                        if (val.selected != "") {
                            strselect = ' selected="' + val.selected + '"';
                        }
                        $selectPosition.append('<option value="' + val.id + '" ' + strselect + '>' + val.position_name + '</option>');
                        $selectPosition.trigger("liszt:updated");//update select option
                    })
                }
            });

            $selectDepartment = $("#cbDepartment");
            $.ajax({
                type: "POST",
                url: 'WebSevice/WebService.asmx/LoadDepartmentBy',
                data: param,
                dataType: 'JSON',
                contentType: "application/json; charset=utf-8",
                success: function (data) {
                    var jsonobject = JSON.parse(data.d);
                    //clear 
                    $selectDepartment.html('');
                    $selectDepartment.append('<option value="">Choose a Department</option>');
                    //append a select option
                    $.each(jsonobject, function (key, val) {
                        strselect = '';
                        if (val.selected != "") {
                            strselect = ' selected="' + val.selected + '"';
                        }
                        $selectDepartment.append('<option value="' + val.id + '" ' + strselect + '>' + val.department_name + '</option>');
                        $selectDepartment.trigger("liszt:updated");//update select option
                    })
                }
            });


            //Combo Box  
            $(".chzn-select").chosen();

        }



    </script>
</asp:Content>

