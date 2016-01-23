<%@ Page Title="" Language="VB" MasterPageFile="~/ContentMasterPage.master" AutoEventWireup="false" CodeFile="frmRequestRoom.aspx.vb" Inherits="frmRequestRoom" %>

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
                    <li class="active">Booking</li>
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
                            <h3 class="header smaller lighter blue">Booking</h3>
                            <%--     <div class="table-header">
                            View Demo
                        </div>--%>
                            <div class="dt_out_actions" style="display: none">
                                <div class="btn-group pull-Left">
                                    <button class="btn btn-app btn-info btn-mini no-radius" id="btnPrint" name="btnPrint">
                                        <i class="icon-print bigger-100"></i>
                                        Print
                                    </button>
                                    <button class="btn btn-app btn-success btn-mini no-radius" id="btnAddnew" name="btnAddnew">
                                        <i class="icon-folder-open bigger-100"></i>
                                        Add New
                                    </button>
                                    <button class="btn btn-app btn-danger btn-mini no-radius" id="btnDelete" name="btnDelete">
                                        <i class="icon-trash bigger-100"></i>
                                        Delete
                                    </button>

                                </div>
                            </div>
                        </div>
                <div class="row-fluid" id="divSearchRoom">
                    <div class="span12">
                        <!--PAGE CONTENT BEGINS-->


                      
                        <%-- <table class="table table-striped table-bordered table-hover" id="dt_out"></table>--%>
                        <!--/PAGE CONTENT BEGINS-->


                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" for="lblMeetingTime">Meeting Date</label>

                            </div>
                            <div class="span10">
                                   <div class="row-fluid input-append">
                                    <input class="date-picker span2" id="txtMeetingDate" type="text" data-date-format="dd/mm/yyyy" placeholder="dd/mm/yyyy" />
                                    <span class="add-on">
                                        <i class="icon-calendar"></i>
                                    </span>

                                </div>
                                <span class="help-inline color red" id="lblvalidMeetingDate" style="display: none">This field is required</span>

                            </div>

                        </div>
                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" for="lblPurpose">Purpose</label>

                            </div>
                            <div class="span10">
                                <textarea id="txtPurpose" placeholder="Purpose" style="width: 600px; height: 120px; resize: none;"></textarea>
                                <div class="row-fluid">

                                <span class="help-inline color red" id="lblvalidPurpose" style="display: none;">This field is required</span>

                                </div>
                            </div>

                        </div>
                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" for="lblAtendant">Attendants</label>

                            </div>
                            <div class="span10">
                                <input type="text" class="input-mini" id="txtAttendants"  />

                            </div>

                        </div>
                        <div class="space-2"></div>
                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" for="lblRoomType">Room Type</label>

                            </div>
                            <div class="span10">
                                <select class="chzn-select " id="cbRoomType" data-placeholder="Choose a Room Type...">
                                </select>
                                 <span class="help-inline color red" id="lblvalidRoomType" style="display: none">This field is required</span>

                            </div>

                        </div>
                        <div class="space-2"></div>
                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" for="lblBuilding">Building</label>
                            </div>
                            <div class="span10">
                                <select class="chzn-select" id="cbBuilding" data-placeholder="Choose a Building..." >
                                </select>
                               <span class="help-inline color red" id="lblvalidBuilding" style="display: none">This field is required</span>

                            </div>

                        </div>
                        <div class="space-2"></div>
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
                        <div class="space-2"></div>
                        <div class="row-fluid" style="display:none">
                            <div class="span2"></div>
                            <div class="span10">
                                <div id="tempoption"></div>
                            </div>
                          
                        </div>
                          <div class="space-2"></div>
                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label"></label>
                            </div>
                            <div class="span10">
                                <button class="btn btn-info" type="button" id="btnSearch">
                                    <i class="icon-ok bigger-110"></i>
                                    Serach
                                </button>


                                &nbsp; &nbsp; &nbsp;
									<button class="btn" type="reset" id="btnClear">
                                        <i class="icon-undo bigger-110"></i>
                                        Clear
                                    </button>
                            </div>

                        </div>
                         <div class="space-2"></div>
                        <div class="row-fluid">
                            <div class="span2"></div>
                            <div class="span10">
                    <%--           <label class=" width-100">Data not found</label>--%>
                                   <h3 class="color red" id="lbldatanotfound" style="display:none">Data not found</h3>
                            </div>
                        </div>
                    </div>
                    <%--<table style="width: 100%;">
                        <tr>
                            <td style="width: 20%;" rowspan="2">
                                <label class="control-label" for="lblPurpose">Purpose</label></td>
                            <td style="width: 30%;" rowspan="2">
                                <textarea id="form-field-8" placeholder="Default Text"></textarea>
                            </td>
                            <td style="width: 20%;">
                                <label class="control-label" for="lblMeetingTime">Meeting Time</label></td>
                            <td style="width: 30%;">
                                <div class="control-group">
                                    <div class="row-fluid input-append">
                                        <input class="date-picker" id="id-date-picker-1" type="text" data-date-format="dd-mm-yyyy" />
                                        <span class="add-on">
                                            <i class="icon-calendar"></i>
                                        </span>
                                    </div>
                                </div>
                            </td>
                        </tr>
                        <tr>
                            <td>
                                <label class="control-label" for="lblAtendent">Atendent</label></td>
                            <td>
													<input type="text" class="input-mini" id="spinner1" />

                                </td>
                        </tr>
                        <tr>
                            <td>
                                <label class="control-label" for="lblRoomType">Room Type</label></td>
                            <td>
                                <div>
                                    <select class="chzn-select" id="cbRoomType" data-placeholder="Choose a Room Type...">
                                        <option value="" />
                                        <option value="1" />
                                        ห้องประชุม 1
															<option value="2" />
                                        ห้องประชุม 2
															<option value="3" />
                                        ห้องประชุม 3
															<option value="4" />
                                        ห้องรับแขกกลาง
															<option value="5" />
                                        ห้องส่วนตัวหัวหน้าฝ่าย

                                    </select>
                                </div>
                            </td>
                            <td>
                                <label class="control-label" for="lblBuilding">Building</label></td>
                            <td>
                                <div>
                                    <select class="chzn-select" id="cbBuilding" data-placeholder="Choose a Building...">
                                        <option value="" />
                                        <option value="1" />อาคาร 1
                                        <option value="2" />อาคาร 2
                                        <option value="3" />อาคาร 3
                                     </select>
                                </div>

                            </td>
                        </tr>
                        <tr>
                            <td>&nbsp;</td>
                            <td>&nbsp;</td>
                            <td>&nbsp;</td>
                            <td>&nbsp;</td>
                        </tr>
                    </table>--%>


                    <!--/PAGE CONTENT END-->

                </div>
                <div class="row-fluid" id="divSelectRoom">
                            <div class="span12">
                                <iframe id="iFrame" frameborder="0" style="overflow: hidden; height: 450px; width: 100%" src=""></iframe>
                            </div>
                        </div>
            </div>
            <!--/.row-fluid-->

            <!--/.page-content-->

       <%--     <div class="ace-settings-container" id="ace-settings-container">
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
        </div>
        <script type="text/javascript">
            $(function () {

                //ปฎิธิน
                $('.date-picker').datepicker().next().on(ace.click_event, function () {
                    $(this).prev().focus();
                });

                //Spinner
                $('#txtAttendants').ace_spinner({ value: 0, min: 0, max: 10000, step: 1, icon_up: 'icon-caret-up', icon_down: 'icon-caret-down' });


                $("#btnSearch").click(function () {
                    //SetUserName();
                    var checkvalid = onValid();
                    if (checkvalid == true) {
                        getRoombyContition();
                    }

                    //getRoomTimebyContition();
                    //  setControl();



                    //getRoomTimebyContition();
                })

                $("#btnClear").click(function () {
                    inputClear();
                })

                var dbDate = "2012-03-06";
                var date2 = new Date(dbDate);


                //Populate Select
                populateSelect();


                $("#divSearchRoom").show();
                $("#divSelectRoom").hide();

            });

   

            //Hide Valid
            function onValidHide() {
                $("#lblvalidMeetingDate").hide();
                $("#lblvalidPurpose").hide();

            }
            //Check Valid
            function onValid() {

                var isValid;
                isValid = true;
                var meetingdate = $('#txtMeetingDate').val();
                if (meetingdate == '') {
                    $("#lblvalidMeetingDate").show();
                    isValid = false;
                } else {
                    $("#lblvalidMeetingDate").hide();
                }
                var purpose = $('#txtPurpose').val();
                if (purpose == '') {
                    $("#lblvalidPurpose").show();
                    isValid = false;
                } else {
                    $("#lblvalidPurpose").hide();
                }

                return isValid;
            }

            function getRoombyContition() {

                var purpose = $("#txtPurpose").val();
                var meetingdate = $("#txtMeetingDate").val();
                var attendant = $("#txtAttendants").val();
                var building_id = $("#cbBuilding").val();
                var roomtype_id = $("#cbRoomType").val();
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
                //var strsql = "";
                //if (attendant != "") {
                //    strsql += " and seat_qty <=" + attendant;
                //}
                //if (building_id != "") {
                //    strsql += " and seat_qty <=" + building_id;
                //}
                var userid = $('#' + '<%=Master.FindControl("lblUserID").ClientID%>').text();
                localStorage['purpose'] = purpose;
                localStorage['attendant'] = attendant;
                localStorage['building_id'] = building_id;
                localStorage['roomtype_id'] = roomtype_id;
                localStorage['stroption_id'] = stroption_id;
                localStorage['userid'] = userid;

                var param = "{'attendantfrom':" + JSON.stringify(attendant)
                             + ",'attendantto':" + JSON.stringify(attendant)
                             + ",'building_id':" + JSON.stringify(building_id)
                             + ",'roomtype_id':" + JSON.stringify(roomtype_id)
                             + ",'stroption_id':" + JSON.stringify(stroption_id)
                             + "}";
                $.ajax({
                    type: "POST",
                    url: "WebSevice/WebService.asmx/LoadRoombyContition",
                    data: param,
                    contentType: "application/json; charset=utf-8",
                    dataType: "json",
                    // success: populatedata1
                    success: function (data) {
                        //  returnvalue = data.d;
                        if (data.d != "[]") {
                            $("#iFrame").attr("src", "frmSlotRoom.aspx")
                            $("#divSearchRoom").hide();
                            $("#divSelectRoom").show();
                            $("#lbldatanotfound").hide();
                            localStorage['roomdata'] = data.d;
                            getRoomTimebyContition();
                        } else {
                            $("#lbldatanotfound").show();
                            localStorage['roomdata'] = '';
                            localStorage['roomtimedata'] = '';
                            localStorage['roomdate'] = '';
                        }


                    },
                });

                //var roomsections = [];
                //var roomsections = JSON.parse(getRoombyContition());
                // alert(returnvalue);
                //  return returnvalue;





            }

            function populatedata1(jsonobject) {
                //alert(jsonobject.d);
                localStorage['roomdata'] = jsonobject.d;
            }

            function getRoomTimebyContition() {
                var strdate = $("#txtMeetingDate").val();
                var param = "{'strdate':" + JSON.stringify(strdate) + "}";
                $.ajax({
                    type: "POST",
                    url: "WebSevice/WebService.asmx/LoadBookingBlockbyContition",
                    data: param,
                    contentType: "application/json; charset=utf-8",
                    dataType: "json",
                    success: populatedata2
                    //success: function (data) {
                    //    //  returnvalue = data.d;
                    //    alert(data.d);
                    //    localStorage['roomtimedata'] = data.d;
                    //},
                    //error: onFailed
                });

                //var roomsections = [];
                //var roomsections = JSON.parse(getRoombyContition());
                // alert(returnvalue);
                //  return returnvalue;

            }

            function populatedata2(jsonobject) {
                //  alert(jsonobject.d);
                localStorage['roomtimedata'] = jsonobject.d;
                localStorage['roomdate'] = $("#txtMeetingDate").val();
            }

            function setControl() {
                var checkdata = localStorage['roomdata'];
                if (checkdata != "[]") {
                    $("#iFrame").attr("src", "frmSlotRoom.aspx")
                    $("#divSearchRoom").hide();
                    $("#divSelectRoom").show();
                    $("#lbldatanotfound").hide();
                } else {
                    localStorage['roomdata'] = '';
                    localStorage['roomtimedata'] = '';
                    localStorage['roomdate'] = '';
                    $("#lbldatanotfound").show();
                }
            }
            function populateSelect() {
                var strselect;
                var param = "{'room_id':" + JSON.stringify(0) + "}";
                $selectOption = $("#cbOption");
                $selectOptionTest = $("#tempoption");
                $.ajax({
                    type: "POST",
                    url: 'WebSevice/WebService.asmx/LoadOptionBy',
                    data: param,
                    dataType: 'JSON',
                    contentType: "application/json; charset=utf-8",
                    success: function (data) {
                        var jsonobject = JSON.parse(data.d);
                        //clear 
                        var countall = 1;
                        var countrow = 0;
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
                        //Checkbox list
                        var mod=4;
                        $selectOptionTest.html('');
                        $.each(jsonobject, function (key, val) {
                            alert(countall % mod);
                            if (countall % mod == 0 && countall > 4) {
                                alert('newrow');
                                $selectOptionTest.append('<div class="row-fluid">');
                              }
                                $selectOptionTest.append('<label class="inline">');
                                $selectOptionTest.append('<input name="CheckOption" type="checkbox"  id=' + val.id + ' />');
                                $selectOptionTest.append('<label  class="lbl style="width:250px">&nbsp;' + val.property_name + '&nbsp;</label >');
                                $selectOptionTest.append('</label>');

                                if (countall % mod == 0 && countall > 4) {
                                    $selectOptionTest.append('</div>');
                                }
                                
                  
                                    countall = countall + 1;
                             

                                
         
                        })

                
                    }
                });

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

                var param = "{'id':" + JSON.stringify(0) + "}";
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

            function inputClear() {
                $("#txtMeetingDate").val("");
                $("#txtPurpose").val("");
                $("#txtAttendants").val("");
                populateSelect();
            }

            function NextPage() {
                var txtPurpose = $("#txtPurpose").val();
                // alert(txtPurpose);
                // window.location.href = "frmSelectRoom.aspx";
                SetUserName();
            }

            function SetUserName() {
                var addn = [];
                addn = [{ 'Test': 1, 'Test2': 2 }];
                localStorage['visitordata'] = addn;
                alert(localStorage['visitordata'])
                window.location.href = "frmSelectRoom.aspx";
                //$.session.set("compareLeftContent", addn);
                //alert($.session.get("compareLeftContent"));
            }

            function GetUserName() {


            }
        </script>

</asp:Content>

