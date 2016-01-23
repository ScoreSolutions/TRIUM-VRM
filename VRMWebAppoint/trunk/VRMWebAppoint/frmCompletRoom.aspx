<%@ Page Title="" Language="VB" MasterPageFile="~/ContentMasterPage.master" AutoEventWireup="false" CodeFile="frmCompletRoom.aspx.vb" Inherits="frmCompletRoom" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="Server">
    <form id="form1" runat="server">
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
                    <li class="active">Search Room

<%--                        <a href="frmRequestRoom.aspx">Search Room</a>--%>

                        <span class="divider">
                            <i class="icon-angle-right arrow-icon"></i>
                        </span>
                    </li>

                    <li class="active">Booking Complete</li>
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
                    <h3 class="header smaller lighter blue">Booking Complete</h3>
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
                <div class="row-fluid">
                    <div class="span3"></div>
                        <div class="span6">
                            <div class="profile-user-info profile-user-info-striped">
                                     <div class="profile-info-row">
                                    <div class="profile-info-name" style="width: 150px">
                                        Booking By
                                           
                                    </div>

                                    <div class="profile-info-value" style="margin-left: 160px">
                                        <span id="lblBookingBy">&nbsp;</span>&nbsp;

                                    </div>
                                </div>
                                <div class="profile-info-row">
                                    <div class="profile-info-name" style="width: 150px">
                                        Meeting Date
                                           
                                    </div>

                                    <div class="profile-info-value" style="margin-left: 160px">
                                        <span id="lblMeetingDate">&nbsp;</span>&nbsp;

                                    </div>
                                </div>

                                <div class="profile-info-row">
                                    <div class="profile-info-name" style="width: 150px">Meeting Time</div>

                                    <div class="profile-info-value" style="margin-left: 160px">
                                        <%--   <asp:Label ID="lblNameThai"  Text="&nbsp;"></asp:Label>--%>
                                        <span id="lblMeetingTime">&nbsp;</span>&nbsp;
                                    </div>
                                </div>

                                <div class="profile-info-row">
                                    <div class="profile-info-name" style="width: 150px">Purpose</div>

                                    <div class="profile-info-value" style="margin-left: 160px">
                                        <%--  <asp:Label ID="lblNameEng" runat="server" Text="&nbsp;"></asp:Label>--%>
                                        <span id="lblPurpose">&nbsp;</span>&nbsp;
                                    </div>
                                </div>

                                <div class="profile-info-row">
                                    <div class="profile-info-name" style="width: 150px">Location</div>

                                    <div class="profile-info-value" style="margin-left: 160px">
                                        <%-- <asp:Label ID="lblBirth" runat="server" Text="&nbsp;"></asp:Label>--%>
                                        <span id="lblLocation">&nbsp;</span>&nbsp;
                                    </div>
                                </div>

                        


                            </div>
                        </div>

                   <div class="span3"></div>

                </div>
                <%--  <div class="row-fluid">
                    <div class="span12">
                        <!--PAGE CONTENT BEGINS-->

                        <div class="error-container">
                            <div class="well">
                                <h1 class="grey lighter smaller">
                                    <span class="blue bigger-125">
                                        <i class="icon-mail-forward"></i>
                                        Booking Complete
                                    </span>

                                </h1>

                                <hr />
                                <h3 class="lighter smaller">
                                    <asp:Label ID="lblLine1" runat="server" Text=""></asp:Label>
                                </h3>
                                <h3 class="lighter smaller">
                                    <asp:Label ID="lblLine2" runat="server" Text=""></asp:Label>
                                </h3>
                                <h3 class="lighter smaller">
                                    <asp:Label ID="lblLine3" runat="server" Text=""></asp:Label>
                                </h3>
                                <h3 class="lighter smaller">
                                    <asp:Label ID="lblline4" runat="server" Text=""></asp:Label>
                                </h3>
                                <h3 class="lighter smaller">
                                    <asp:Label ID="lblline5" runat="server" Text=""></asp:Label>
                                </h3>



                                <div class="space"></div>

                                <%--	<div>
										<h4 class="lighter smaller">Meanwhile, try one of the following:</h4>

										<ul class="unstyled spaced inline bigger-110">
											<li>
												<i class="icon-hand-right blue"></i>
												Read the faq
											</li>

											<li>
												<i class="icon-hand-right blue"></i>
												Give us more info on how this specific error occurred!
											</li>
										</ul>
									</div>--%>

                <hr />
                <div class="space"></div>

                <div class="row-fluid">
                    <div class="center">
                        <a href="frmRequestRoom.aspx?RowIDMenu=20" class="btn btn-grey">
                            <i class="icon-arrow-left"></i>
                            Go back to new booking
                        </a>


                    </div>
                </div>
            </div>
        </div>

        <!--PAGE CONTENT ENDS-->

            <!--/.row-fluid-->

        <!--/.page-content-->

        <%-- <div class="ace-settings-container" id="ace-settings-container">
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
      
        <script type="text/javascript">
            $(function () {
                Loaddata();

            });


            function Loaddata() {
                var id =localStorage['prebooking_id'];
                var param = "{'id':" + JSON.stringify(id) + "}"

                // var param = "{'strID':" + JSON.stringify(value) + "}";

                $.ajax({
                    type: "POST",
                    url: "WebSevice/WebService.asmx/GetContractById",
                    data: param,
                    contentType: "application/json; charset=utf-8",
                    dataType: "json",
                    success: function (data) {
                        var strvalue = JSON.parse(data.d);
                        if (strvalue.length == 1) {
                            var fullanme = $('#' + '<%=Master.FindControl("lblfullname").ClientID%>').text();
                            $("#lblBookingBy").text(fullanme);
                            $("#lblMeetingDate").text(strvalue[0].start_contract_date);
                            $("#lblMeetingTime").text(strvalue[0].start_contract_time + '-' + strvalue[0].end_contract_time);
                            $("#lblPurpose").text(strvalue[0].purpose);
                            $("#lblLocation").text('Room name:' + strvalue[0].room_name + ' Building name :' + strvalue[0].building_name);
                            localStorage.clear();
                        }
                        //var jsonobject = JSON.parse(data.d);
                        //alert(jsonobject);
                        //$.each(jsonobject, function (key, val) {
                        //    $("lblMeetingDate").text(val.start_contract_date);
                        //    $("lblMeetingTime").text(val.start_contract_time + '-' + val.end_contract_time);
                        //    $("lblPurpose").text(val.purpose);
                        //    $("lblLocation").text('Room name:' + val.room_name + ' Building name :' + val.building_name);
                        //})
                    }
                });
            }
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

