<%@ Page Title="" Language="VB" MasterPageFile="~/ContentMasterPage.master" AutoEventWireup="false" CodeFile="frmSelectRoomNotTime.aspx.vb" Inherits="frmSelectRoomNotTime" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="Server">
    <form id="form1" runat="server">
        <link href="assets/js/image-picker/image-picker.css" rel="stylesheet" />
        <script src="assets/js/image-picker/image-picker.js"></script>

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
                    <li>

                        <a href="frmRequestRoom.aspx">Search Room</a>

                        <span class="divider">
                            <i class="icon-angle-right arrow-icon"></i>
                        </span>
                    </li>
                    <li class="active">Booking Room</li>
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
                            <h3 class="header smaller lighter blue">Booking Room</h3>
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
                        <%-- <table class="table table-striped table-bordered table-hover" id="dt_out"></table>--%>
                        <!--/PAGE CONTENT BEGINS-->
                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" for="lblPurpose">Date</label>
                            </div>
                            <div class="span10">
                                <div class="row-fluid input-append">
                                    <input class="date-picker" id="txtDate" type="text"  runat="server" />
                                    <span class="add-on">
                                        <i class="icon-calendar"></i>
                                    </span>
                                </div>
                          

                            </div>
                        </div>
                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" for="lblPurpose">Time</label>
                            </div>
                            <div class="span10">
                                <div class="input-append bootstrap-timepicker">
                                    <input id="timepicker1" type="text" class="input-small" runat="server" />
 
                                    <span class="add-on">
                                        <i class="icon-time"></i>
                                    </span>
                                  
                                </div>
                            </div>
                        </div>
                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" for="lblPurpose">Room</label>
                            </div>

                            <div class="span10">
                                <%--                                <select class="image-picker masonry show-html">
  <option data-img-src="images/Room1.jpg"  value="1">Cute Kitten 1</option>
                                  
  <option data-img-src="images/Room2.jpg"  value="2">Cute Kitten 2</option>
  <option data-img-src="images/Room3.jpg" value="3">Cute Kitten 3</option>
  <option data-img-src="images/Room4.jpg" style="width:50px;height:50px;" value="4">Cute Kitten 4</option>
</select>--%>
                                <select class="image-picker show-html" runat="server" id="cbRoom">
                                    <option data-img-src="images/Room1.jpg" value="1">Metting Room 1  </option>
                                    <option data-img-src="images/Room2.jpg" value="2">Metting Room 2  </option>
                                    <option data-img-src="images/Room3.jpg" value="3">Metting Room 3  </option>
                                    <option data-img-src="images/Room4.jpg" value="4">Metting Room 4  </option>
                                    <option data-img-src="images/Room5.jpg" value="5">Metting Room 5  </option>
                                    <option data-img-src="images/Room6.jpg" value="6">Metting Room 6  </option>
                                    <option data-img-src="images/Room7.jpg" value="7">Metting Room 7  </option>
                                     <option data-img-src="images/Room8.png" value="8">Metting Room 8   </option>
                                    <%--  <option data-img-src="images/Room1.jpg" value="8">  Page 8  </option>
  <option data-img-src="images/Room1.jpg" value="9">  Page 9  </option>
  <option data-img-src="images/Room1.jpg" value="10"> Page 10 </option>
  <option data-img-src="images/Room1.jpg" value="11"> Page 11 </option>
  <option data-img-src="images/Room1.jpg" value="12"> Page 12 </option>--%>
                                </select>


                            </div>

                        </div>

                        <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" for="lblBuilding2"></label>
                            </div>
                            <div class="span10">
                                <button class="btn btn-info" type="button" runat="server" id="btnSearch" onserverclick="btnSearch_ServerClick">
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


                <!--/.span-->
            </div>
            <!--/.row-fluid-->

            <!--/.page-content-->

            <div class="ace-settings-container" id="ace-settings-container">
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
        </div>
        <script type="text/javascript">

            function NextPage(id) {
                window.location.href = "frmCompletRoom.aspx?id=" + id;
             
            }

            $(function () {

                $("select").imagepicker({
                    hide_select: false,
                    show_label: true
                })

                //Combo Box
                $(".chzn-select").chosen();

                //ปฎิธิน
                $('.date-picker').datepicker().next().on(ace.click_event, function () {
                    $(this).prev().focus();
                });

                

                //Spinner
                $('#spinner1').ace_spinner({ value: 0, min: 0, max: 10000, step: 1, icon_up: 'icon-caret-up', icon_down: 'icon-caret-down' });


                //$('#timepicker1').timepicker({
                //    minuteStep: 1,
                //    showSeconds: false,
                //    showMeridian: false
                //});

                //$('#timeformatExample1').timepicker({ 'timeFormat': 'H:i:s' });

                //$('#timepicker1').timepicker({
                //    minuteStep: 1,
                //    showSeconds: false,
                //    showMeridian: false
                //});

                //$('#timeformatExample1').timepicker({ 'timeFormat': 'H:i:s' });

                $("#<%= timepicker1.ClientID%>").timepicker({
                        minuteStep: 1,
                        showSeconds: false,
                        showMeridian: false
                });

        

            });



            //function NextPage() {
            //    var txtPurpose = $("#txtPurpose").val();
            //    // alert(txtPurpose);
            //    // window.location.href = "frmSelectRoom.aspx";
            //    SetUserName();
            //}

            //function SetUserName() {
            //    alert(23223);

            //    $.session.set("compareLeftContent", "value");
            //    alert($.session.get("compareLeftContent"));


            //}

            //function GetUserName() {


            //}
        </script>
    </form>
</asp:Content>

