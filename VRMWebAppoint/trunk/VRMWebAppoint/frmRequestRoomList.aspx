<%@ Page Title="" Language="VB" MasterPageFile="~/ContentMasterPage.master" AutoEventWireup="false" CodeFile="frmRequestRoomList.aspx.vb" Inherits="frmRequestRoomList" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="Server">
    <link href="assets/js/image-picker/image-picker.css" rel="stylesheet" />
    <script src="assets/js/image-picker/image-picker.js"></script>
    <script src="assets/js/x-editable/bootstrap-editable.min.js"></script>
    <script src="assets/js/x-editable/ace-editable.min.js"></script>
    <link rel="stylesheet" href="assets/css/bootstrap-editable.css" />
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
                <li class="active">List Booking</li>
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
                    <h3 class="header smaller lighter blue" id="headertext">List Booking</h3>

                    <%--                    <div class="row-fluid">
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
                    </div>--%>
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
                                <label class="control-label" for="lblDatefrom">Date</label>
                            </div>
                            <div class="span2">

                                <div class="row-fluid input-append">
                                    <input class="date-picker width-55" id="txtDateFrom" type="text" data-date-format="dd/mm/yyyy" />
                                    <span class="add-on">
                                        <i class="icon-calendar"></i>
                                    </span>

                                    <%--<span class="help-inline">To</span>--%>
                                </div>
                                <span class="help-inline color red" id="lblvalidDateFrom" style="display: none">This field is required</span>


                            </div>
   
                            <div class="span8"></div>


                        </div>

                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" for="lblsrattime">Start Time</label>
                            </div>

                            <div class="span2">
                                <div class="input-append bootstrap-timepicker">
                                    <input id="txtTimepickerstart" type="text" class="input-small width-55" />

                                    <span class="add-on">
                                        <i class="icon-time"></i>
                                    </span>

                                    <span class="help-inline">To</span>
                                </div>
                                <span class="help-inline color red" id="lblvalidTimepickerstart" style="display: none">This field is required</span>


                            </div>
                            <div class="span2">
                                <div class="input-append bootstrap-timepicker">
                                    <input id="txtTimepickerend" type="text" class="input-small width-55" />

                                    <span class="add-on">
                                        <i class="icon-time"></i>
                                    </span>

                                </div>
                                <span class="help-inline color red" id="lblvalidTimepickerend" style="display: none">This field is required</span>

                            </div>
                            <div class="span6"></div>

                        </div>

                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" for="lblBuilding">Building</label>
                            </div>
                            <div class="span10">
                                <select class="chzn-select" id="cbBuilding">
                                </select>
                                <span class="help-inline color red" id="lblvalidBuilding" style="display: none">This field is required</span>

                            </div>
                        </div>
                        <div class="space-2"></div>
                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" for="lblRoom">Room</label>
                            </div>

                            <div class="span10">

                                <select class="chzn-select" id="cbRoom">
                                </select>
                                <span id="linkroomdetail" class="help-button" data-placement="left" title="Room detail" onclick="onView();">?</span>
                                <span class="help-inline color red" id="lblvalidRoom" style="display: none">This field is required</span>

                            </div>

                        </div>

                        <div class="space-2"></div>
                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" for="lblPurpose">Purpose</label>

                            </div>
                            <div class="span10">
                                <textarea id="txtPurpose" placeholder="Purpose" style="width: 600px; height: 60px; resize: none;" maxlength="255"></textarea>
                                <span class="help-inline color red" id="lblvalidPurpose" style="display: none">This field is required</span>

                            </div>

                        </div>
                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" id="lblBuildingActive">Active</label>
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
                             <div class="span2"></div>
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
                        <div style="display: none">
                            <h3 class="header smaller lighter blue">Visitor</h3>
                            <div class="row-fluid">
                                <div class="span12">
                                    <button class="btn btn-small btn-success" id="btnVisitorAdd" name="btnVisitorAdd">
                                        <i class=" icon-plus"></i>
                                        Add New
                                    </button>

                                    <span class="help-inline color red" id="lblvalidVisitor" style="display: none">Visitor is required please add new visitor</span>

                                </div>



                            </div>
                            <div class="space-2"></div>
                            <div class="row-fluid">

                                <div class="span12">
                                    <table class="table table-striped table-bordered table-hover" id="dt_visitor"></table>
                                    <%-- <div class="widget-box transparent" runat="server" id="divRecentActivities1">
                      
                                <div class="widget-body" id="divRecentActivities2">
                                    <div class="widget-main padding-8">
                                        <div id="profile-feed-1" class="profile-feed">
                                            <div id="divRecentActivitiesDetail"></div>
                                        </div>
                                    </div>
                                </div>

                                  </div>
                                <div id="divVisitoradd">

                                    <div class="span12">

                                        <input id="txtCardID" type="text" style="width: 150px;" placeholder="Identification Number" />

                                        <input id="txtFullName" type="text" style="width: 150px;" placeholder="Full Name" />

                                        <input id="txtCompany" type="text" style="width: 150px;" placeholder="Company Name" />
                                        <span style="font-size:larger" id="btnVisitoAdd"><i class="icon-plus"></i></span>
                                    </div>--%>

                                    <%--    <div class="span6">
                                        <button class="btn btn-success btn-small inline" id="btnVisitoAdd" name="btnVisitoAdd">
                                            <i class="icon-plus"></i>

                                        </button>
                                        <button class="btn btn-success btn-small inline" id="btnVisitoClear" name="btnVisitoClear">
                                            <i class="icon-undo"></i>

                                        </button>
                                    </div>--%>



                                    <%--    <asp:Button ID="Button1" runat="server" Text="PostBack"></asp:Button>

                                    <input type="button" value="Check for PostBack" onclick="JavaScript: alert('IsPostBack: ' + isPostBack());">


                                    --%>
                                    <%--      <input type="hidden" id="clientSideIsPostBack" name="clientSideIsPostBack">--%>
                                </div>
                            </div>
                            <div class="space-4"></div>
                        </div>

                    </div>

                    <div id="dialog-view" class="profile-user-info profile-user-info-striped" style="display: none">
                        <div class="profile-info-row">
                            <div class="profile-info-name">
                                <span class="control-label" id="lblImage">Room Image</span>
                            </div>
                            <div class="profile-info-value">

                                <a href="images/No_image.gif" id="aimg" style="display: none;"></a>
                                <img id="img" src="images/No_image.gif" style="height: 150px; width: 200px; cursor: pointer;" />
                                <div id="dialog-image" style="display: none">
                                    <img id="imgPopup" src="images/No_image.gif" style="height: 350px; width: 500px;" />
                                </div>

                                <div id="base" style="display: none"></div>
                                <div id="basepath" style="display: none"></div>
                                <div id="basename" style="display: none"></div>


                            </div>

                        </div>

                        <div class="profile-info-row">
                            <div class="profile-info-name">
                                <span class="control-label">Room Name</span>
                            </div>
                            <div class="profile-info-value">
                                <span class="control-label" id="lblRoomDesc">&nbsp;</span>&nbsp;
                            </div>


                        </div>
                        <div class="profile-info-row">
                            <div class="profile-info-name">
                                <span class="control-label">Room Type</span>

                            </div>
                            <div class="profile-info-value">
                                <span class="control-label" id="lblRoomTypeDesc">&nbsp;</span>&nbsp;
                            </div>


                        </div>

                        <div class="profile-info-row">
                            <div class="profile-info-name">
                                <span class="control-label">Building</span>
                            </div>
                            <div class="profile-info-value">
                                <span class="control-label" id="lblBuildingDesc">&nbsp;</span>&nbsp;
                            </div>

                        </div>

                        <div class="profile-info-row">
                            <div class="profile-info-name">
                                <span class="control-label">Floor</span>
                            </div>
                            <div class="profile-info-value">
                                <span class="control-label" id="lblFloorDesc">&nbsp;</span>&nbsp;

                            </div>

                        </div>

                        <div class="profile-info-row">
                            <div class="profile-info-name">
                                <span class="control-label">Attendance</span>
                            </div>
                            <div class="profile-info-value">
                                <span class="control-label" id="lblAttendanceDesc">&nbsp;</span>&nbsp;
                            </div>

                        </div>
                        <div class="profile-info-row">

                            <div class="profile-info-name">
                                <span class="control-label">Option</span>
                            </div>
                            <div class="profile-info-value">
                                <span class="control-label" id="lblOptionDesc">&nbsp;</span>&nbsp;
                            </div>

                        </div>






                    </div>

                    <div id="dialog-visitor-edit">
                        <div class="row-fluid">
                            <div class="span4">
                                <label class="control-label">Identification Number</label>
                            </div>
                            <div class="span8">
                                <input id="txtCardID" maxlength="13" type="text" style="width: 300px;" placeholder="Identification Number" onkeypress="return Numbers(event)" />
                                <span class="help-inline color red" id="lblvalidCardID" style="display: none">This field is required</span>
                                <span class="help-inline color red" id="lblvalidCardID_Format" style="display: none">incorrect format </span>

                            </div>
                        </div>
                        <div class="row-fluid">
                            <div class="span4">
                                <label class="control-label">Visitor Name</label>
                            </div>
                            <div class="span8">
                                <input id="txtVisitorName" maxlength="255" type="text" style="width: 300px;" placeholder="Visitor Name" />
                                <span class="help-inline color red" id="lblvalidVisitorName" style="display: none">This field is required</span>

                            </div>
                        </div>
                        <div class="row-fluid">
                            <div class="span4">
                                <label class="control-label">Company Name</label>
                            </div>
                            <div class="span8">
                                <input id="txtCompany" maxlength="255" type="text" style="width: 300px;" placeholder="Company Name" />
                                <span class="help-inline color red" id="lblvalidCompany" style="display: none">This field is required</span>

                            </div>
                        </div>
                    </div>
                    <%--   <div id="dialog-view" class="profile-user-info profile-user-info-striped" style="display: none">
                <div class="profile-info-row">
                    <div class="profile-info-name">Building</div>

                    <div class="profile-info-value" >
                        <span id="lblBuildingDesc">&nbsp;</span>&nbsp;
                    </div>
                </div>
                <div class="profile-info-row">
                    <div class="profile-info-name" >Floor</div>

                    <div class="profile-info-value">
                        <span id="lblFloorDesc">&nbsp;</span>&nbsp;
                    </div>

                </div>
                <div class="profile-info-row">
                    <div class="profile-info-name" >Room</div>

                    <div class="profile-info-value">
                        <span id="lblRoomDesc">&nbsp;</span>&nbsp;
                    </div>


                </div>
                <div class="profile-info-row">
                    <div class="profile-info-name" >Purpose</div>

                    <div class="profile-info-value">
                        <span id="lblPurposeDesc">&nbsp;</span>&nbsp;
                    </div>


                </div>
                <div class="profile-info-row" style="display:none">
                    <div class="profile-info-name" >Date</div>

                    <div class="profile-info-value">
                        <span id="lblDateDesc">&nbsp;</span>&nbsp;
                    </div>

                </div>

            </div>--%>
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
            localStorage['visitordata'] = '';
            var strvisitor;
            //Load Room
            var oTable;
            var isAddNew = false;
            LoadData();
            LoadDataVisitor(0);

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
                //timecheck($('#txtTimepickerstart').val(), $('#txtTimepickerend').val());
                var ret = onValid();
                if (ret == true) {
                    onConfirmSave();
                }
            });

            $("#btnClear").click(function () {
                clearInput();
            });

            $("#btnVisitorAdd").click(function () {
                onEditVisitor(0);
                //addVisitor();
                //$('#txtId').editable({
                //    type: 'text',
                //    name: 'txtId'
                //});
                //$('#txtFullanme').editable({
                //    type: 'text',
                //    name: 'txtFullanme'
                //});
                //$('#txtCompany').editable({
                //    type: 'text',
                //    name: 'txtCompany'
                //});
                //addDatavisitor();
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
            populateSelectRoomByValue(0);
            populateSelectBuildingByValue(0);
            $('#cbBuilding').change(function () {
                populateSelectRoom();
            });

            $('#cbRoom').change(function () {
                populateSelectBuilding($(this).val(), $('#cbBuilding').val());
            });



            //ปฎิธิน
            $('.date-picker').datepicker().next().on(ace.click_event, function () {
                $(this).prev().focus();
            });
            //time
            $("#txtTimepickerstart").timepicker({
                minuteStep: 30,
                showSeconds: false,
                showMeridian: false
            });
            //time
            $("#txtTimepickerend").timepicker({
                minuteStep: 30,
                showSeconds: false,
                showMeridian: false
            });
            //รูปภาพ
            $("#cbRoom").imagepicker({
                hide_select: false,
                show_label: true
            })


            //Hide div or other
            $("#dialog-edit").hide();
            $("#dialog-visitor-edit").hide();
            $("#btnBack").hide();



        });


        //Call
        function LoadData() {
            var strcondition = '';
            var param = "{ 'strcontition':" + JSON.stringify(strcondition) + "}";
            var dataurl = 'WebSevice/WebService.asmx/LoadBookingBy';
            $.ajax({
                "type": "POST",
                "dataType": 'json',
                "contentType": "application/json; charset=utf-8",
                "url": dataurl,
                "data": param,
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
                                "sTitle": "Purpose",
                                "sType": "string",
                                "sDefaultContent": "",
                                "mDataProp": "purpose"

                            },
                            {
                                "sTitle": "Meeting Date",
                                "sType": "string",
                                "sDefaultContent": "",
                                "mDataProp": "meetingcontractdate"

                            },
                            {
                                "sTitle": "Meeting Time",
                                "sType": "string",
                                "sDefaultContent": "",
                                "mDataProp": "meetingcontracttime"

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
                { "sWidth": "10%", "aTargets": [1] },
                { "sWidth": "10%", "aTargets": [2] },
                { "sWidth": "5%", "aTargets": [3] },
                { "sWidth": "22%", "aTargets": [4] },
                { "sWidth": "15%", "aTargets": [5] },
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
            localStorage['visitordata'] = ''
            //if (id == 0) {
            //    $("#headertext").text("Add Contract");
            //} else {
            //    $("#headertext").text("Edit Contract");
            //}
            onValidHide();
            $("#HiddenId").val(id);
            var param = "{'id':" + JSON.stringify(id) + "}";

            $.ajax({
                type: "POST",
                url: "WebSevice/WebService.asmx/GetContractById",
                data: param,
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: function (data) {
                    var strvalue = JSON.parse(data.d);

                    if (strvalue.length == 1) {
                        $("#HiddenId").val(strvalue[0].id);
                        $('#txtDateFrom').val(strvalue[0].start_contract_date);
                        $('#txtTimepickerstart').val(strvalue[0].start_contract_time);
                        $('#txtTimepickerend').val(strvalue[0].end_contract_time);
                        populateSelectRoomByValue(strvalue[0].ms_meeting_room_id)
                        populateSelectBuilding(strvalue[0].ms_meeting_room_id, strvalue[0].ms_building_id)
                        $('#txtPurpose').val(strvalue[0].purpose);
                        if (strvalue[0].active_status == "Y") {
                            $("#ckbActive").prop("checked", true);
                        } else {
                            $("#ckbActive").prop("checked", false);
                        }
                        LoadDataVisitor(strvalue[0].id);
                    } else {
                        $("#HiddenId").val(0);
                        $('#txtDateFrom').val("");
                        $('#txtTimepickerstart').val("");
                        $('#txtTimepickerend').val("");
                        populateSelectRoomByValue(0)
                        populateSelectBuildingByValue(0)
                        $('#txtPurpose').val("");
                        $("#ckbActive").prop("checked", false);
                        LoadDataVisitor(0);
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

        function onEditVisitor(id) {
            onValidVisitorHide();
            //Find data in current session
            if (id > 0) {
                var jsonobject = JSON.parse(localStorage['visitordata']);
                var editjsonobject = getObjects(jsonobject, 'id', id);

                $.each(editjsonobject, function (key, val) {
                    $('#txtCardID').val(val.id_cardno);
                    $('#txtVisitorName').val(val.visitor_name);
                    $('#txtCompany').val(val.visitor_company_name);
                })

            } else {
                clearvisitor();
            }

            //Dialog
            $("#dialog-visitor-edit").dialog({
                autoOpen: false,
                resizable: false,
                width: "600px",
                modal: true,
                buttons: {
                    "Save": function () {
                        var checkvalid = onValidVisitor();
                        if (checkvalid == true) {

                            if (checkid_duplicate($('#txtCardID').val()) == false) {
                                onAlert("Identification number already exists. Please modify Identification number");
                            } else {
                                onSaveVisitor(id);
                                onAlert("Add Complete");
                                $(this).dialog("close");
                            }

                        }


                    },
                    "Close": function () {
                        $(this).dialog("close");
                    }

                }
                ,
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

            $("#dialog-visitor-edit").dialog("option", "title", titledialog).dialog("open");

        }



        //Save Contract
        function onSave() {

            var id = $("#HiddenId").val();
            var userid = $('#' + '<%=Master.FindControl("lblUserID").ClientID%>').text();
            var startdate = $('#txtDateFrom').val();
            var enddate = startdate;//date from date to use same day 
            var starttime = $('#txtTimepickerstart').val();
            var endtime = $('#txtTimepickerend').val();
            var room_id = $('#cbRoom').val();
            var purpose = $('#txtPurpose').val();
            var active_status = $('input[name="ckbActive"]:checked').length;
            if (active_status == 0) {
                active_status = "N";
            } else {
                active_status = "Y";
            }


            var jsonobject = localStorage['visitordata'];
            //var sd = new Date();
            //var ed = new Date();
            ////sd.format("yyyy/MM/dd hh:mm");
            ////ed.format("yyyy/MM/dd hh:mm");
            //sd = startdate;
            //ed = enddate;
            //var scurr_date = sd.getDate();
            //var scurr_month = sd.getMonth();
            //var scurr_year = sd.getFullYear();
            //var scurr_minutes = AddZero(sd.getHours()) + ':' + AddZero(sd.getMinutes());
            //var ecurr_date = ed.getDate();
            //var ecurr_month = ed.getMonth();
            //var ecurr_year = ed.getFullYear();
            //var ecurr_minutes = AddZero(ed.getHours()) + ':' + AddZero(ed.getMinutes());
            //var sdate = scurr_month + "/" + scurr_date + "/" + scurr_year;
            //var edate = ecurr_month + "/" + ecurr_date + "/" + ecurr_year;

            var param = "{'id':" + JSON.stringify(id)
                + ",'startdate':" + JSON.stringify(startdate)
                + ",'enddate':" + JSON.stringify(enddate)
                + ",'starttime':" + JSON.stringify(starttime)
                + ",'endtime':" + JSON.stringify(endtime)
                + ",'room_id':" + JSON.stringify(room_id)
                + ",'purpose':" + JSON.stringify(purpose)
                + ",'strvisitor':" + JSON.stringify(jsonobject)
                + ",'active_status':" + JSON.stringify(active_status)
                + ",'userid':" + JSON.stringify(userid) + "}";


            $.ajax({
                type: "POST",
                url: "WebSevice/WebService.asmx/SaveBookingFromEdit",
                data: param,
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: onBookingSuccess,
                error: onFailed
            });
        }


        function AddZero(num) {
            return (num >= 0 && num < 10) ? "0" + num : num + "";
        }

        //Save Contract
        function onSaveVisitor(id) {
            //var id = $("#HiddenId").val();
            var userid = $('#' + '<%=Master.FindControl("lblUserID").ClientID%>').text();
            var cardid = $('#txtCardID').val();
            var visitor = $('#txtVisitorName').val();
            var company = $('#txtCompany').val();

            //running no
            var rows = $("#dt_visitor").dataTable().fnGetNodes();

            //data in current session
            var jsonobject = JSON.parse(localStorage['visitordata']);
            var aaData = [];
            aaData = jsonobject;
            //add data in current session

            if (id == 0) {
                aaData.push({
                    "no": parseInt(rows.length) + 1,
                    "id": parseInt(rows.length) + 1,
                    "id_cardno": cardid,
                    "visitor_name": visitor,
                    "visitor_company_name": company
                });
            } else {//edit data in current session
                for (var i = 0; i < aaData.length; i++) {
                    if (aaData[i].id == id) {
                        aaData[i].id_cardno = cardid;
                        aaData[i].visitor_name = visitor;
                        aaData[i].visitor_company_name = company;
                        break;
                    }
                }

            }


            //update data in session
            localStorage['visitordata'] = JSON.stringify(aaData);

            // Reload
            LoadDataVisitor(0);
            clearvisitor();


            //$.each(jsonobject, function (key, val) {
            //    // alert(val.id + '' + val.room_name);
            //    alert(val.id);
            //    alert(val.id_cardno);
            //    alert(val.visitor_name);
            //    alert(val.visitor_company_name);

            //})


            //var editjsonobject =  getObjects(jsonobject, 'id', '2');

            //$.each(editjsonobject, function (key, val) {
            //    alert("Found");
            //    alert(val.id);
            //    alert(val.id_cardno);
            //    alert(val.visitor_name);
            //    alert(val.visitor_company_name);
            //})


        }
        //Search in json object
        function getObjects(obj, key, val) {
            var objects = [];
            for (var i in obj) {
                if (!obj.hasOwnProperty(i)) continue;
                if (typeof obj[i] == 'object') {
                    objects = objects.concat(getObjects(obj[i], key, val));
                } else if (i == key && obj[key] == val) {
                    objects.push(obj);
                }
            }
            return objects;
        }

        //Delete Room
        function onDelete(id) {
            var param = "{'id':" + JSON.stringify(id) + "}";

            $.ajax({
                type: "POST",
                url: "WebSevice/WebService.asmx/DeleteContract",
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

        //Confirm save contract
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
                                    var checkvalid = onValid();
                                    if (checkvalid == true) {
                                            div.dialog("close");
                                            onSave();

                                    }


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
        function onBookingSuccess(result) {
            if (result.d > 0) {
                onAlert("Save Complete");
                LoadData();
                clickEndEdit();
            } else if (result.d = -1) {
                onAlert("Date and time duplicate Please modify date or time ");
            }
            else {
                onAlert("Save Fail");

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
            $("#lblvalidDateFrom").hide();
            $("#lblvalidTimepickerstart").hide();
            $("#lblvalidTimepickerend").hide();
            $("#lblvalidBuilding").hide();
            $("#lblvalidRoom").hide();
            $("#lblvalidPurpose").hide();

        }
        //Check Valid
        function onValid() {

            var isValid;
            isValid = true;
            var startdate = $('#txtDateFrom').val();
            var enddate = startdate;
            var starttime = $('#txtTimepickerstart').val();
            var endtime = $('#txtTimepickerend').val();
            var building_id = $('#cbBuilding').val();
            var room_id = $('#cbRoom').val();
            var purpose = $('#txtPurpose').val();
            //var datacount = JSON.parse(localStorage['visitordata']);

            if (startdate == '') {
                $("#lblvalidDateFrom").show();
                isValid = false;
            } else {
                $("#lblvalidDateFrom").hide();
            }

            if (starttime == '') {
                $("#lblvalidTimepickerstart").show();
                isValid = false;
            } else {
                $("#lblvalidTimepickerstart").hide();
            }
            if (endtime == '') {
                $("#lblvalidTimepickerend").show();
                isValid = false;
            } else {
                $("#lblvalidTimepickerend").hide();
            }

            if (building_id == '') {
                $("#lblvalidBuilding").show();
                isValid = false;
            } else {
                $("#lblvalidBuilding").hide();

            }
            if (room_id == '') {
                $("#lblvalidRoom").show();
                isValid = false;
            } else {
                $("#lblvalidRoom").hide();

            }
            if (purpose == '') {
                $("#lblvalidPurpose").show();
                isValid = false;
            } else {
                $("#lblvalidPurpose").hide();

            }
            //if (datacount.length == 0) {
            //    $("#lblvalidVisitor").show();
            //    isValid = false;
            //} else {
            //    $("#lblvalidVisitor").hide();

            //}



            return isValid;
        }

        //Hide Valid
        function onValidVisitorHide() {
            $("#lblvalidCardID").hide();
            $("#lblvalidCardID_Format").hide();
            $("#lblvalidVisitorName").hide();
            $("#lblvalidCompany").hide();
        }

        function onValidVisitor() {

            var isValid;
            isValid = true;

            var id_card = $('#txtCardID').val();
            var visitor = $('#txtVisitorName').val();
            var company = $('#txtCompany').val();


            if (id_card == '') {
                $("#lblvalidCardID").show();
                $("#lblvalidCardID_Format").hide();
                isValid = false;
            } else {
                if (checkID(id_card) == false) {
                    $("#lblvalidCardID_Format").show();
                    $("#lblvalidCardID").hide();
                    isValid = false;
                } else {
                    $("#lblvalidCardID").hide();
                    $("#lblvalidCardID_Format").hide();
                }

            }
            if (visitor == '') {
                $("#lblvalidVisitorName").show();
                isValid = false;
            } else {

                $("#lblvalidVisitorName").hide();

            }
            if (company == '') {
                $("#lblvalidCompany").show();
                isValid = false;
            } else {
                $("#lblvalidCompany").hide();

            }

            return isValid;
        }

        function checkid_duplicate(id_cardno) {
            var jsonobject = JSON.parse(localStorage['visitordata']);
            var checkjsonobject = getObjects(jsonobject, 'id_cardno', id_cardno);
            if (checkjsonobject.length == 0) {
                return true;
            } else {
                return false;
            }
        }

        function Numbers(e) {
            var keynum;
            var keychar;
            var numcheck;
            if (window.event) {// IE
                keynum = e.keyCode;
            }
            else if (e.which) {// Netscape/Firefox/Opera
                keynum = e.which;
            }
            if (keynum == 13 || keynum == 8 || typeof (keynum) == "undefined") {
                return true;
            }
            keychar = String.fromCharCode(keynum);
            numcheck = /^[0-9]$/;
            return numcheck.test(keychar);
        }

        function checkID(id) {
            if (id.length != 13) return false;
            for (i = 0, sum = 0; i < 12; i++)
                sum += parseFloat(id.charAt(i)) * (13 - i);
            if ((11 - sum % 11) % 10 != parseFloat(id.charAt(12)))
                return false;
            return true;
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
           // $("#HiddenId").val(0);
            $('#txtDateFrom').val("");
            $('#txtTimepickerstart').val("");
            $('#txtTimepickerend').val("");
            populateSelectRoomByValue(0)
            populateSelectBuildingByValue(0)
            $('#txtPurpose').val("");
            $("#ckbActive").prop("checked", false);
            localStorage['visitordata'] = '';
            LoadDataVisitor(0);
        }
        function clearvisitor() {
            $('#txtCardID').val("");
            $('#txtVisitorName').val("");
            $('#txtCompany').val("");
        }
        //Populate Select
        function populateSelectRoom() {
            var strselect;
            var id = $('#cbBuilding').val();
            var param = "{'id':" + JSON.stringify(id) + "}";
            $selectRoom = $('#cbRoom');
            var id_room_selected = $selectRoom.val();

            $.ajax({
                type: "POST",
                url: 'WebSevice/WebService.asmx/LoadRoomByBuildingId',
                dataType: 'JSON',
                data: param,
                contentType: "application/json; charset=utf-8",
                success: function (data) {
                    var jsonobject = JSON.parse(data.d);

                    //clear 
                    $selectRoom.html('');
                    $selectRoom.append('<option value="">Choose a room</option>');
                    //append a select option
                    $.each(jsonobject, function (key, val) {
                        strselect = '';
                        if (id_room_selected == val.id) {
                            strselect = ' selected="' + val.selected + '"';
                        }
                        $selectRoom.append('<option value="' + val.id + '" ' + strselect + '>' + val.room_name + '</option>');
                        $selectRoom.trigger("liszt:updated");//update select option

                    })
                    $selectRoom.trigger("liszt:updated");//update select option

                }
            });
        }

        function populateSelectBuilding(ms_meetingroom_id, ms_building_id) {
            var strselect;
            var param = "{'id':" + JSON.stringify(ms_meetingroom_id) + "}";
            $selectBuilding = $("#cbBuilding");
            var id_building_selected = ms_building_id;//$selectBuilding.val();
            if (ms_meetingroom_id == "") {
                $("#linkroomdetail").hide();
            } else {
                $("#linkroomdetail").show();
            }
            $.ajax({
                type: "POST",
                url: 'WebSevice/WebService.asmx/LoadBuildingByRoomId',
                dataType: 'JSON',
                data: param,
                contentType: "application/json; charset=utf-8",
                success: function (data) {
                    var jsonobject = JSON.parse(data.d);
                    //clear 
                    $selectBuilding.html('');
                    $selectBuilding.append('<option value="">Choose a building</option>');
                    //append a select option
                    $.each(jsonobject, function (key, val) {
                        strselect = '';
                        if (id_building_selected == val.id) {
                            strselect = ' selected="' + val.selected + '"';
                        }
                        $selectBuilding.append('<option value="' + val.id + '" ' + strselect + '>' + val.building_name + '</option>');
                        $selectBuilding.trigger("liszt:updated");//update select option
                    })
                    $selectBuilding.trigger("liszt:updated");//update select option
                }
            });

        }

        function populateSelectRoomByValue(id) {
            var strselect;
            var param = "{'id':" + JSON.stringify(id) + "}";
            $selectRoom = $("#cbRoom");
            $.ajax({
                type: "POST",
                url: 'WebSevice/WebService.asmx/LoadRoomByValue',
                data: param,
                dataType: 'JSON',
                contentType: "application/json; charset=utf-8",
                success: function (data) {
                    var jsonobject = JSON.parse(data.d);
                    //clear 
                    $selectRoom.html('');
                    $selectRoom.append('<option value="">Choose a Room </option>');
                    //append a select option
                    $.each(jsonobject, function (key, val) {
                        strselect = '';
                        if (val.selected != "") {
                            strselect = ' selected="' + val.selected + '"';
                        }
                        $selectRoom.append('<option value="' + val.id + '" ' + strselect + '>' + val.room_name + '</option>');
                        $selectRoom.trigger("liszt:updated");//update select option
                    })
                }
            });

            //Combo Box  
            $(".chzn-select").chosen();
        }

        function populateSelectBuildingByValue(id) {
            var strselect;
            var param = "{'id':" + JSON.stringify(id) + "}";
            $selectBuilding = $("#cbBuilding");
            $.ajax({
                type: "POST",
                url: 'WebSevice/WebService.asmx/LoadBuildingByValue',
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




        function onView() {
            var id = $('#cbRoom').val();
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
                        $("#lblBuildingDesc").text(strvalue[0].building_name);
                        $("#lblRoomDesc").text(strvalue[0].room_name);
                        $("#lblRoomTypeDesc").text(strvalue[0].room_type_name);
                        $("#lblFloorDesc").text(strvalue[0].floor);
                        $("#lblAttendanceDesc").text(strvalue[0].attendance);
                        $("#lblOptionDesc").text(strvalue[0].stroption);
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
                    } else {
                        $("#lblBuildingDesc").text("");
                        $("#lblRoomDesc").text("");
                        $("#lblRoomTypeDesc").text("");
                        $("#lblFloorDesc").text("");
                        $("#lblAttendanceDesc").text("");
                        $("#lblOptionDesc").text("");
                        clearImage();

                    }
                },
                error: function (data) {
                }
            });


            $("#dialog-view").dialog({
                autoOpen: false,
                resizable: false,
                width: "600px",
                modal: true,
                show: {
                    effect: 'size',
                    duration: 500
                },
                hide: {
                    effect: 'size',
                    duration: 500
                }
            });
            $("#dialog-view").dialog("option", "title", "View").dialog("open");
            // $("#dialog-view").dialog("option", "maxHeight", 600);

        }


        function addVisitor() {
            $visitor = $("#divRecentActivitiesDetail");

            strvisitor = '       <div class="profile-activity clearfix">'
                              + '<div class="profile-info-value"><span class="editable" id="txtId">Identification Number</span></div>'
                              + '<div class="profile-info-value"><span class="editable" id="txtFullanme">Identification Number</span></div>'
                              + '<div class="profile-info-value"><span class="editable" id="txtCompany">Identification Number</span></div>'
                              + '</div>'

            $visitor.append(strvisitor);
        }


        function LoadDataVisitor(id) {
            var param = "{'id':" + JSON.stringify(id) + "}";
            var dataurl = 'WebSevice/WebService.asmx/LoadVisitorByContract';
            $.ajax({
                "type": "POST",
                "dataType": 'json',
                "contentType": "application/json; charset=utf-8",
                "url": dataurl,
                "data": param,
                "success": PopulateGridVisitor
            });
        }

        function PopulateGridVisitor(jsondata) {
            var jsonobject = JSON.parse(jsondata.d);
            // window.localStorage.setItem("visitordata", jsonobject);
            var yetVisited = localStorage['visitordata'];
            if (yetVisited.length > 0) {

            }
            else {
                localStorage['visitordata'] = jsondata.d;
            }
            //alert(yetVisited);

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
                                "mDataProp": "id_cardno"

                            },
                            {
                                "sTitle": "Visitor Name",
                                "sType": "string",
                                "sDefaultContent": "",
                                "mDataProp": "visitor_name",
                            },
                            {
                                "sTitle": "Company ",
                                "sType": "string",
                                "sDefaultContent": "",
                                "mDataProp": "visitor_company_name",
                            },

                            {
                                "sTitle": "Action",
                                "bSortable": false,
                                "fnRender": function (obj) {
                                    return '<div class="hidden-phone visible-desktop action-buttons">'
                                            + '<a href="#"style="display: none;"  data-toggle="modal" class="blue"  title="View" onClick="onView_visitor(' + obj.aData.id + ');">'
                                            + '<span class="blue"><i class="icon-zoom-in bigger-130"></i></span>'
                                            + '</a>'
                                            + '&nbsp;'
                                            + '<a href="#"   class="Green"  title="Edit" onClick="onEditVisitor(' + obj.aData.id + ');">'
                                            + '<span class="green"><i class="icon-pencil bigger-130"></i></span>'
                                            + '</a>'
                                            + '&nbsp;'
                                            + '<a href="#"   class="Red"  title="Delete" onclick="onConfirmDeleteVisitor(' + obj.aData.no + ');" >'
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
                                            + '						<a href="#"    class="tooltip-success" data-rel="tooltip" title="Edit" onClick="onEditVisitor(' + obj.aData.id + ');">'
                                            + '							<span class="green">'
                                            + '								<i class="icon-edit bigger-120"></i>'
                                            + '							</span>'
                                            + '						</a>'
                                            + '					</li>'
                                            + ''
                                            + '					<li>'
                                            + '						<a href="#"   class="tooltip-error" data-rel="tooltip" title="Delete" onclick="onConfirmDeleteVisitor(' + obj.aData.no + ');">'
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

            var aaData = getDatavissitor();
            //aaData.push({
            //    "no": "1000",
            //    "cardno": "Bob Jr.",
            //    "fullname_thai": "Hs Var",
            //    "id": "3"
            //});
            //aaData.push({
            //    "no": "2000",
            //    "cardno": "Bob Jr.",
            //    "fullname_thai": "Hs Var",
            //    "id": "2"
            //});

            //aaData.splice(1, 4);

            oTable = $('#dt_visitor').dataTable({
                "aaData": aaData,
                "bAutoWidth": false,
                "aoColumnDefs": [
                { "sWidth": "10%", "aTargets": [0] },
                { "sWidth": "20%", "aTargets": [1] },
                { "sWidth": "20%", "aTargets": [2] },
                { "sWidth": "30%", "aTargets": [3] },
                { "sWidth": "10%", "aTargets": [4] },
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

        //function PopulateGridVisitorReload() {
        //    var columns = [

        //                    {
        //                        "sTitle": "No",
        //                        "sType": "numeric",
        //                        "mDataProp": "no",
        //                        "bUseRendered": false

        //                    },
        //                    {
        //                        "sTitle": "Identification Number",
        //                        "sType": "string",
        //                        "sDefaultContent": "",
        //                        "mDataProp": "cardno"

        //                    },
        //                    {
        //                        "sTitle": "Name - Last name ",
        //                        "sType": "string",
        //                        "sDefaultContent": "",
        //                        "mDataProp": "fullname_thai",
        //                    },
        //                    {
        //                        "sTitle": "Company ",
        //                        "sType": "string",
        //                        "sDefaultContent": "",
        //                        "mDataProp": "fullname_thai",
        //                    },

        //                    {
        //                        "sTitle": "Action",
        //                        "bSortable": false,
        //                        "fnRender": function (obj) {
        //                            return '<div class="hidden-phone visible-desktop action-buttons">'
        //                                    + '<a href="#" style="display: none;" data-toggle="modal" class="blue"  title="View" onClick="onView_visitor(' + obj.aData.id + ');">'
        //                                    + '<span class="blue"><i class="icon-zoom-in bigger-130"></i></span>'
        //                                    + '</a>'
        //                                    + '&nbsp;'
        //                                    + '<a href="#"   class="Green"  title="Edit" onClick="onEdit(' + obj.aData.id + ');">'
        //                                    + '<span class="green"><i class="icon-pencil bigger-130"></i></span>'
        //                                    + '</a>'
        //                                    + '&nbsp;'
        //                                    + '<a href="#"   class="Red"  title="Delete" onclick="deleteDatavisitor(' + obj.aData.id + ');" >'
        //                                    + '<span class="red"><i class="icon-trash bigger-130"></i></span>'
        //                                    + '</a>'
        //                                    + '</div>'
        //                                    + '<div class="hidden-desktop visible-phone">'
        //                                    + '			<div class="inline position-relative">'
        //                                    + '				<button class="btn btn-minier btn-primary dropdown-toggle" data-toggle="dropdown">'
        //                                    + '					<i class="icon-cog icon-only bigger-110"></i>'
        //                                    + '				</button>'
        //                                    + ''
        //                                    + '				<ul class="dropdown-menu dropdown-icon-only dropdown-yellow pull-right dropdown-caret dropdown-close">'
        //                                    + '					<li>'
        //                                    + '						<a href="#" style="display: none;"  class="tooltip-info" data-rel="tooltip" title="View" onClick="onView_visitor(' + obj.aData.id + ');">'
        //                                    + '							<span class="blue">'
        //                                    + '								<i class="icon-zoom-in bigger-120"></i>'
        //                                    + '							</span>'
        //                                    + '						</a>'
        //                                    + '					</li>'
        //                                    + ''
        //                                    + '					<li>'
        //                                    + '						<a href="#"    class="tooltip-success" data-rel="tooltip" title="Edit" onClick="onEdit(' + obj.aData.id + ');">'
        //                                    + '							<span class="green">'
        //                                    + '								<i class="icon-edit bigger-120"></i>'
        //                                    + '							</span>'
        //                                    + '						</a>'
        //                                    + '					</li>'
        //                                    + ''
        //                                    + '					<li>'
        //                                    + '						<a href="#"  class="tooltip-error" data-rel="tooltip" title="Delete" onclick="deleteDatavisitor(' + obj.aData.id + ');">'
        //                                    + '							<span class="red">'
        //                                    + '								<i class="icon-trash bigger-120"></i>'
        //                                    + '							</span>'
        //                                    + '						</a>'
        //                                    + '					</li>'
        //                                    + '				</ul>'
        //                                    + '			</div>'
        //                                    + '		</div>'


        //                            ;
        //                        },
        //                        "sDefaultContent": "",
        //                        "bUseRendered": false
        //                    }
        //    ];

        //    var aaData = SetDatavissitor();
        //    //aaData.push({
        //    //    "no": "1000",
        //    //    "cardno": "Bob Jr.",
        //    //    "fullname_thai": "Hs Var",
        //    //    "id": "3"
        //    //});
        //    //aaData.push({
        //    //    "no": "2000",
        //    //    "cardno": "Bob Jr.",
        //    //    "fullname_thai": "Hs Var",
        //    //    "id": "2"
        //    //});

        //    //aaData.splice(1, 4);

        //    oTable = $('#dt_visitor').dataTable({
        //        "aaData": aaData,
        //        "bAutoWidth": false,
        //        "aoColumnDefs": [
        //        { "sWidth": "10%", "aTargets": [0] },
        //        { "sWidth": "20%", "aTargets": [1] },
        //        { "sWidth": "20%", "aTargets": [2] },
        //        { "sWidth": "30%", "aTargets": [3] },
        //        { "sWidth": "10%", "aTargets": [4] },
        //        ],
        //        "aoColumns": columns,
        //        "bDestroy": true,
        //        "fnDrawCallback": function () {
        //            //  alert($("#checkall").val());
        //            //var strCheckAll = $("input[name=checkall]:checked").length;
        //            //if (strCheckAll == 1) {
        //            //    $("#checkall").prop("checked", false);
        //            //}

        //        }

        //    });



        //}

        function SetDatavissitor() {
            var jsonobject = JSON.parse(localStorage['visitordata']);
            var aaData = [];
            aaData = jsonobject;
            return aaData;
        }

        function getDatavissitor() {
            var jsonobject = JSON.parse(localStorage['visitordata']);
            var aaData = [];
            aaData = jsonobject;
            //aaData.push({
            //    "no": "1000",
            //    "cardno": "Bob Jr.",
            //    "fullname_thai": "Hs Var",
            //    "id": "3"
            //});
            //aaData.push({
            //    "no": "2000",
            //    "cardno": "Bob Jr.",
            //    "fullname_thai": "Hs Var",
            //    "id": "2"
            //});
            //aaData.push({
            //    "no": "3000",
            //    "cardno": "Bob Jr.",
            //    "fullname_thai": "Hs Var",
            //    "id": "2"
            //});

            return aaData;
        }

        function addDatavisitor() {
            var jsonobject = JSON.parse(localStorage['visitordata']);
            var aaData = [];
            aaData = jsonobject;
            aaData.push({
                "no": "100000",
                "cardno": "Bob Jr.",
                "fullname_thai": "Hs Var",
                "id": "30"
            });
            //alert(aaData.text);
            alert(JSON.stringify(aaData));
            localStorage['visitordata'] = JSON.stringify(aaData);

            // PopulateGridVisitorReload();
            LoadDataVisitor(0);
        }

        function deleteDatavisitor(no) {
            var jsonobject = JSON.parse(localStorage['visitordata']);
            var aaData = [];
            aaData = jsonobject;
            aaData.splice(parseInt(no) - 1, 6);
            localStorage['visitordata'] = JSON.stringify(aaData);
            LoadDataVisitor(0);
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
                                    deleteDatavisitor(id);
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

        function dateCheck(from, to) {

            var d1 = from.split("/");
            var d2 = to.split("/");

            var sfrom = new Date(d1[2], d1[1] - 1, d1[0] + ' 12:30');  // -1 because months are from 0 to 11
            var sto = new Date(d2[2], d2[1] - 1, d2[0] + ' 12:30');

            if (sto < sfrom) {
                return false;
            } else {
                return true;
            }

            //    if ((cDate <= lDate && cDate >= fDate)) {
            //        return true;
            //    }
            //    return false;
        }

        function toSeconds(time_str) {
            // Extract hours, minutes and seconds
            var parts = time_str.split(':');
            // compute  and return total seconds
            return parts[0] * 3600 + // an hour has 3600 seconds
            parts[1] * 60 + // a minute has 60 seconds
            +
            '00'; // seconds
        }

        function timecheck(from, to) {
            var difference = Math.abs(toSeconds(from) - toSeconds(to));

            // format time differnece
            var result = [
                Math.floor(difference / 3600), // an hour has 3600 seconds
                Math.floor((difference % 3600) / 60), // a minute has 60 seconds
                difference % 60
            ];
            // 0 padding and concatation
            result = result.map(function (v) {
                return v < 10 ? '0' + v : v;
            }).join(':');
            alert(result);
        }

    </script>

</asp:Content>


