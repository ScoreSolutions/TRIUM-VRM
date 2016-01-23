<%@ Page Title="" Language="VB" MasterPageFile="~/ContentMasterPage.master" AutoEventWireup="false" CodeFile="frmRoom.aspx.vb" Inherits="frmRoom" %>

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
                <li class="active">Room</li>
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
                    <h3 class="header smaller lighter blue">Room</h3>

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



                        <%--      <div class="dt_out_actions">
                            <div class="btn-group pull-Left">
                                <button class="btn btn-small btn-info" id="btnPrint" name="btnPrint" style="display: none">
                                    <i class="icon-print"></i>
                                    Print
                                </button>
                            
                                <button class="btn btn-small btn-danger" id="btnDelete" name="btnDelete" style="display: none">
                                    <i class="icon-trash"></i>
                                    Delete
                                </button>

                            </div>
                        </div>--%>
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
                            <div class="row-fluid">
                        <div class="span2">
                            <label class="control-label" id="lblRoomName">Room Name</label>
                        </div>
                        <div class="span10">
                        <input type="text" id="txtRoomName" class="limited" data-maxlength="50" maxlength="50" style="width:40%">
                         <span class="help-inline color red" id="lblvalidroom_name" style="display: none">This field is required</span>
                        </div>
                     
                  
                </div>
                    <div class="row-fluid">
                    <div class="span2">
                        <label class="control-label" for="lblRoomType">Room Type</label>

                    </div>
                    <div class="span10">
                        <select class="chzn-select" id="cbRoomType" data-placeholder="Choose a Room Type..."></select>
                        <span class="help-inline color red" id="lblvalidms_room_type_id" style="display: none">This field is required</span>                   
                    </div>

                 
                    </div>
                    <div class="space-2"></div>
                <div class="row-fluid">
                    <div class="span2">
                        <label class="control-label" for="lblBuilding">Building</label>
                    </div>
                    <div class="span10">
                        <select class="chzn-select" id="cbBuilding" data-placeholder="Choose a Building...">
               
                        </select>
                        <span class="help-inline color red" id="lblvalidms_building_id" style="display: none">This field is required</span>
                    </div>

                </div>
                        <div class="space-2"></div>       
                <div class="row-fluid">
                    <div class="span2">
                        <label class="control-label" for="lblFloor">Floor</label>
                    </div>
                    <div class="span10">
                        <input type="text" class="input-mini" id="txtFloor" />
                        <span class="help-inline color red" id="lblvalidfloor" style="display: none">This field is required</span>
                      
                    </div>

                </div>

                   <div class="row-fluid">
                    <div class="span2">
                        <label class="control-label" for="lblAtendent">Attendance</label>
                    </div>
                    <div class="span10">
                        <input type="text" class="input-mini" id="txtAttendance" />
                        <span class="help-inline color red" id="lblvalidattendance" style="display: none">This field is required</span>
                        <span class="help-inline color red" id="lblvalidattendancezero" style="display: none">Minimum attendance is 1</span>
                        <span class="help-inline color red" id="lblvalidattendancenumeric" style="display: none">Attendance is not numeric</span>

                    </div>

                </div>
                <div class="row-fluid">
           
                    <div class="span2">
                        <label class="control-label">Option</label>
                    </div>
                    <div class="span10">
                        <select class="chzn-select" multiple="multiple" id="cbOption" data-placeholder="Choose a Option"...">
     
                        </select>
                         <span class="help-inline color red" id="lblvalidoption" style="display: none">This field is required</span>
                    </div>

                </div>

       

                  <div class="space-4"></div>
                          <div class="row-fluid">
                    <div class="span2">
                        <label class="control-label" id="lblImage">Room Image</label>
                    </div>
                    <div class="span7" >
                        <div class="row-fluid">
                            <div class="span4">
                      <a href="images/No_image.gif"   id="aimg" style="display:none;"  ></a>
<%--				<a href="images/No_image.gif" rel="prettyPhoto"   id="aimg"><img   id="img" src="images/No_image.gif"  style="height: 150px; width: 200px;" /></a>--%>
                    <img   id="img" src="images/No_image.gif"  style="height: 150px; width: 200px; cursor: pointer;" />
                     <div id="dialog-image" style="display:none">
                    <img   id="imgPopup" src="images/No_image.gif"  style="height: 350px; width: 500px;" />
                </div>
                             
                                 
                          

			
                                      <%-- <img id="img" src="images/No_image.gif" style="height: 150px; width: 200px;" />--%>
                       
                                    <div id="base" style="display:none"></div>
                                    <div id="basepath" style="display:none" ></div>
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
                                      <span class="help-inline" id="lblvalidfiletype" >file type : gif,png,jpg,jpeg</span>
                            <span class="help-inline" id="lblvalidfilesize" >file type : size less than 1MB</span>
                           </div>
                              <div class="span4"></div>
                        </div>
          <%--                  <div class="span5">
                                
                                    <img id="img" src="images/No_image.gif" style="height: 150px; width: 200px;" />
                                    <div id="base" style="display:none"></div>
                                    <div id="basename"></div>
                              
                                <div class="space-2"></div>
                                
                                    <span class="btn btn-default btn-mini btn-file">Browse&hellip; 
                                    <input type='file' id="roomimagefile" />
                                    </span>
                                    <button class="btn btn-danger btn-mini" id="btnClearImage">
                                    Clear
                                    </button>
                                
                            </div>
                            <div class="span5">
                            <span class="help-inline" id="lblvalidfiletype" >file type : gif,png,jpg,jpeg</span>
                            <span class="help-inline" id="lblvalidfilesize" >file type : size less than 2 MB</span>

                            </div>--%>
                         
                    </div>
                  <%--  <div class="span6"></div>--%>
                  </div>

                         <div class="row-fluid">
                    <div class="span2">
                        <label class="control-label" id="lblRoomActive">Active</label>
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
            populateSelect(0);

            //Hide div or other
            $("#dialog-edit").hide();
            $("#btnBack").hide();



        });




        //Call
        function LoadData() {
            var dataurl = 'WebSevice/WebService.asmx/LoadRoom';
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
                                "sTitle": "Room Name",
                                "sType": "string",
                                "sDefaultContent": "",
                                "mDataProp": "room_name"

                            },
                            {
                                "sTitle": "Room Type",
                                "sType": "string",
                                "sDefaultContent": "",
                                "mDataProp": "room_type_name"

                            },
                           {
                               "sTitle": "Building Name",
                               "sType": "string",
                               "sDefaultContent": "",
                               "mDataProp": "building_name"

                           },
                            {
                                "sTitle": "Floor",
                                "sType": "string",
                                "sDefaultContent": "",
                                "mDataProp": "floor"

                            },
                            {
                                "sTitle": "Attendance",
                                "sType": "string",
                                "sDefaultContent": "",
                                "mDataProp": "seat_qty"

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
                { "sWidth": "8%", "aTargets": [0] },
                { "sWidth": "20%", "aTargets": [1] },
                { "sWidth": "12%", "aTargets": [2] },
                { "sWidth": "20%", "aTargets": [3] },
                { "sWidth": "10%", "aTargets": [4] },
                { "sWidth": "10%", "aTargets": [5] },
                { "sWidth": "10%", "aTargets": [6] },
                { "sWidth": "10%", "aTargets": [7] }
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
                url: "WebSevice/WebService.asmx/GetRoomById",
                data: param,
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: function (data) {
                    var strvalue = JSON.parse(data.d);

                    if (strvalue.length == 1) {
                        $("#HiddenId").val(strvalue[0].id);
                        $("#txtRoomName").val(strvalue[0].room_name);
                        $("#txtFloor").val(strvalue[0].floor);
                        $("#txtAttendance").val(strvalue[0].attendance);
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
                        $("#txtRoomName").val("");
                        $("#txtFloor").val("");
                        $("#txtAttendance").val("");
                        clearImage();
                        populateSelect(0);
                        $("#ckbActive").prop("checked", false);
                    }
                },
                error: function (data) {
                    alert(1);
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
            var room_name = $('#txtRoomName').val();
            var floor = $('#txtFloor').val();
            var attendance = $('#txtAttendance').val();
            var ms_room_type_id = $('#cbRoomType').val();
            var ms_building_id = $('#cbBuilding').val();
        // var stroption_id_temp = $('#cbOption').val();
            var room_active = $('input[name="ckbActive"]:checked').length;
            var strimagebase64 = $("#base").text();
            var strimagename = $("#basename").text();
            var strimagepath = $("#basepath").text();

            if (room_active == 0) {
                room_active = "N"
            } else {
                room_active = "Y"
            }


            var stroption_id = '';
            var stroption_id_temp = [];
            try {
                stroption_id_temp = $('#cbOption').val();
                for (var i = 0; i < stroption_id_temp.length; i++) {
                    if (stroption_id == '') {
                        stroption_id = stroption_id_temp[i];
                    } else {
                        stroption_id = stroption_id + ',' + stroption_id_temp[i];
                    }
                }
            }
            catch (e) {
                // alert("error")
            }

            var param = "{'id':" + JSON.stringify(id)
                + ",'room_name':" + JSON.stringify(room_name)
                + ",'ms_room_type_id':" + JSON.stringify(ms_room_type_id)
                + ",'attendance':" + JSON.stringify(attendance)
                + ",'ms_building_id':" + JSON.stringify(ms_building_id)
                + ",'floor':" + JSON.stringify(floor)
                + ",'stroption_id':" + JSON.stringify(stroption_id)
                + ",'strimagebase64':" + JSON.stringify(strimagebase64)
                + ",'strimagename':" + JSON.stringify(strimagename)
                + ",'strimagepath':" + JSON.stringify(strimagepath)
                + ",'userid':" + JSON.stringify(userid)
                + ",'active':" + JSON.stringify(room_active) + "}";


            $.ajax({
                type: "POST",
                url: "WebSevice/WebService.asmx/SaveRoom",
                data: param,
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: onRoomSuccess,
                error: onFailed
            });
        }
        //Delete Room
        function onDelete(id) {
            var param = "{'id':" + JSON.stringify(id) + "}";

            $.ajax({
                type: "POST",
                url: "WebSevice/WebService.asmx/DeleteRoom",
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
        function onRoomSuccess(result) {
            if (result.d == "YES") {
                onAlert("Save Complete");
                LoadData();
                clickEndEdit();
            } else {
                if (result.d == "DUPLICATE") {
                    onAlert("Room name already exists. Please modify room name.");
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
            $("#lblvalidroom_name").hide();
            $("#lblvalidattendance").hide();
            $("#lblvalidattendancezero").hide();
            $("#lblvalidattendancenumeric").hide();
            $("#lblvalidms_room_type_id").hide();
            $("#lblvalidms_building_id").hide();
            $("#lblvalidoption").hide();
            $('#lblvalidfloor').hide();

        }
        //Check Valid
        function onValid() {

            var isValid;
            isValid = true;
            var room_name = $('#txtRoomName').val();
            var attendance = $('#txtAttendance').val();
            var ms_room_type_id = $('#cbRoomType').val();
            var ms_building_id = $('#cbBuilding').val();
            var floor = $('#txtFloor').val();
            var room_active = $('input[name="ckbActive"]:checked').length;
            var strimagebase64 = $("#base").text();
            var strimagepath = $("#basename").text();

            var stroption_id = '';
            var stroption_id_temp = [];
            try {
                stroption_id_temp = $('#cbOption').val();
                if (stroption_id_temp != 'null') {
                    for (var i = 0; i < stroption_id_temp.length; i++) {
                        if (stroption_id == '') {
                            stroption_id = stroption_id_temp[i];
                        } else {
                            stroption_id = stroption_id + ',' + stroption_id_temp[i];
                        }
                    }
                }
            }
            catch (e) {
                //alert('error');
            }

            if (room_name == '') {
                $("#lblvalidroom_name").show();
                isValid = false;
            } else {
                $("#lblvalidroom_name").hide();
            }
            if (attendance == '') {
                $("#lblvalidattendance").show();
                $("#lblvalidattendancezero").hide();
                $("#lblvalidattendancenumeric").hide();
                isValid = false;
            } else {
                if (attendance == 0) {
                    $("#lblvalidattendance").hide();
                    $("#lblvalidattendancezero").show();
                    $("#lblvalidattendancenumeric").hide();
                    isValid = false;
                } else {
                    if ($.isNumeric(attendance) == false) {
                        $("#lblvalidattendance").hide();
                        $("#lblvalidattendancezero").hide();
                        $("#lblvalidattendancenumeric").show();
                        isValid = false;
                    } else {
                        $("#lblvalidattendance").hide();
                        $("#lblvalidattendancezero").hide();
                        $("#lblvalidattendancenumeric").hide();
                    }

                }


            }
            if (ms_room_type_id == '') {
                $("#lblvalidms_room_type_id").show();
                isValid = false;
            } else {
                $("#lblvalidms_room_type_id").hide();

            }
            if (ms_building_id == '') {
                $("#lblvalidms_building_id").show();
                isValid = false;
            } else {
                $("#lblvalidms_building_id").hide();

            }



            if (stroption_id == '') {
                $("#lblvalidoption").show();
                isValid = false;
            } else {
                $("#lblvalidoption").hide();

            }

            if (floor == '') {
                $("#lblvalidfloor").show();
                isValid = false;
            } else {
                $("#lblvalidfloor").hide();
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
            $("#txtRoomName").val("");
            $("#txtFloor").val("");
            $("#txtAttendance").val("");
            clearImage();
            populateSelect(0);
            $("#ckbActive").prop("checked", false);
        }
        //Populate Option By Room ID
        function populateSelect(room_id) {
            var strselect;
            var param = "{'room_id':" + JSON.stringify(room_id) + "}";
            $selectOption = $("#cbOption");
            $.ajax({
                type: "POST",
                url: 'WebSevice/WebService.asmx/LoadOptionBy',
                data: param,
                dataType: 'JSON',
                contentType: "application/json; charset=utf-8",
                success: function (data) {
                    var jsonobject = JSON.parse(data.d);
                    //clear 
                    $selectOption.html('');
                    //append a select option
                    $.each(jsonobject, function (key, val) {
                        strselect = '';
                        if (val.selected != "") {
                            strselect = ' selected="' + val.selected + '"';
                        }
                        $selectOption.append('<option value="' + val.id + '" ' + strselect + '>' + val.property_name + '</option>');
                        $selectOption.trigger("liszt:updated");//update select option
                    })
                }
            });

            //Populate Check Select
            $select = $("#cbRoomType");
            $.ajax({
                type: "POST",
                url: 'WebSevice/WebService.asmx/LoadRoomTypeBy',
                data: param,
                dataType: 'JSON',
                contentType: "application/json; charset=utf-8",
                success: function (data) {
                    var jsonobject = JSON.parse(data.d);
                    //clear 
                    $select.html('');
                    $select.append('<option value="">Choose a Room type</option>');
                    //append a select option
                    $.each(jsonobject, function (key, val) {
                        strselect = '';
                        if (val.selected != "") {
                            strselect = ' selected="' + val.selected + '"';
                        }

                        $select.append('<option value="' + val.id + '" ' + strselect + '>' + val.room_type_name + '</option>');
                        $select.trigger("liszt:updated");//update select option
                    })
                }
            });

            $selectBuilding = $("#cbBuilding");
            $.ajax({
                type: "POST",
                url: 'WebSevice/WebService.asmx/LoadBulidingBy',
                data: param,
                dataType: 'JSON',
                contentType: "application/json; charset=utf-8",
                success: function (data) {
                    var jsonobject = JSON.parse(data.d);
                    //clear 
                    $selectBuilding.html('');
                    $selectBuilding.append('<option value="">Choose a Building</option>');
                    //append a select option
                    $.each(jsonobject, function (key, val) {
                        strselect = '';
                        if (val.selected != "") {
                            strselect = ' selected="' + val.selected + '"';
                        }
                        $selectBuilding.append('<option value="' + val.id + '" ' + strselect + '>' + val.building_name + '</option>');
                        $selectBuilding.trigger("liszt:updated");//update select option
                    })
                }
            });


            //Combo Box  
            $(".chzn-select").chosen();

        }


    </script>


    	<%--<script type="text/javascript" charset="utf-8">
    	    $(document).ready(function () {
    	        //$("area[rel^='prettyPhoto']").prettyPhoto();
    	        $("a[rel^='prettyPhoto']").prettyPhoto({
    	            animation_speed: 'normal', /* fast/slow/normal */
    	            slideshow: 3000, /* false OR interval time in ms */
    	            autoplay_slideshow: false, /* true/false */
    	            show_title: true, /* true/false */
    	            allow_resize: true, /* Resize the photos bigger than viewport. true/false */
    	            theme: 'light_square', /* light_rounded / dark_rounded / light_square / dark_square / facebook */
    	            social_tools: false,
    	            modal: true, /* If set to true, only the close button will close the window */
    	        });

    	       // $(".gallery:first a[rel^='prettyPhoto']").prettyPhoto({ animation_speed: 'normal', theme: 'facebook', slideshow: 3000, autoplay_slideshow: false });
    	       // $(".gallery:gt(0) a[rel^='prettyPhoto']").prettyPhoto({ animation_speed: 'fast', slideshow: 10000, hideflash: true });

    	        //$("#custom_content a[rel^='prettyPhoto']:first").prettyPhoto({
    	        //    custom_markup: '<div id="map_canvas" style="width:260px; height:265px"></div>',
    	        //    changepicturecallback: function () { initialize(); }
    	        //});

    	        //$("#custom_content a[rel^='prettyPhoto']:last").prettyPhoto({
    	        //    custom_markup: '<div id="bsap_1259344" class="bsarocks bsap_d49a0984d0f377271ccbf01a33f2b6d6"></div><div id="bsap_1237859" class="bsarocks bsap_d49a0984d0f377271ccbf01a33f2b6d6" style="height:260px"></div><div id="bsap_1251710" class="bsarocks bsap_d49a0984d0f377271ccbf01a33f2b6d6"></div>',
    	        //    changepicturecallback: function () { _bsap.exec(); }
    	        //});
    	    });
			</script>--%>


</asp:Content>

