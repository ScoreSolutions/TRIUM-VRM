<%@ Page Title="" Language="VB" MasterPageFile="~/ContentMasterPage.master" AutoEventWireup="false" CodeFile="frmProfileView.aspx.vb" Inherits="frmProfileView" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="Server">
    <%--   <form id="form1" runat="server">--%>
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
                    <a id="alink" href="frmBlackList.aspx">Blacklist</a>

                    <span class="divider">
                        <i class="icon-angle-right arrow-icon"></i>
                    </span>
                </li>
                <li class="active">Visitor Profile</li>
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



                        <%-- <h3 class="header smaller lighter blue">Visitor Profile</h3>--%>
                        <div class="span12">
                            <h3 class="header smaller lighter blue">Visitor Profile</h3>
                        </div>


                        <div class="dt_out_actions" style="display: none">
                            <div class="btn-group pull-Left">

                                <button class="btn btn-app btn-info btn-mini no-radius" id="btnPrint" name="btnPrint" style="display: none">
                                    <i class="icon-print bigger-100"></i>
                                    Print
                                </button>
                                <button class="btn btn-app btn-success btn-mini no-radius" id="btnAddnew" name="btnAddnew" style="display: none">
                                    <i class="icon-folder-open bigger-100"></i>
                                    Add New
                                </button>
                                <button class="btn btn-app btn-danger btn-mini no-radius" id="btnDelete" name="btnDelete" style="display: none">
                                    <i class="icon-trash bigger-100"></i>
                                    Delete
                                </button>

                            </div>
                        </div>
                    </div>
                    <div class="row-fluid">
                        <div class="btn-group pull-left">
                            <button class="btn btn-small" id="btnBack" name="btnBack">
                                <i class=" icon-undo"></i>
                                Back
                            </button>
                        </div>

                    </div>
                    <div class="space-4"></div>
                </div>
            </div>
            <div class="row-fluid">
                <div class="span12">
                    <!--PAGE CONTENT BEGINS-->




                    <div>
                        <div id="user-profile-1" class="user-profile row-fluid">
                            <div class="span3">
                                <div class="center">
                                    <span class="profile-picture" style="height: 225px; width: 250px;">
                                        <%--                                        <img id="avatar" class="editable" alt="Alex's Avatar" src="assets/avatars/profile-pic.jpg" />--%>
                                        <img id="picavatar" alt="" src="assets/avatars/profile-pic.jpg" style="height: 225px; width: 200px;" />

                                    </span>

                                    <div class="space-4"></div>

                                    <div class="width-95 label label-info label-large ">
                                        <div class="inline position-relative">
                                            <a href="#" class="user-title-label dropdown-toggle" data-toggle="dropdown">
                                                <%-- <i class="icon-circle light-green middle"></i>
                                                &nbsp;--%>
                                                <span id="lblUnderImage" class="white middle bigger-120"></span>
                                            </a>
                                        </div>
                                    </div>
                                </div>

                                <div class="space-6"></div>

                                <div class="profile-contact-info" runat="server">
                                    <div class="profile-contact-links align-left">
                                        <a class="btn btn-link" href="#" id="btnAdd">
                                            <i class="icon-plus-sign bigger-120 green"></i>
                                            Add as a black list
                                        </a>

                                        <a class="btn btn-link" href="#" id="btnRemove">
                                            <i class=" icon-remove-sign bigger-120 pink"></i>
                                            Delete as a black list
                                        </a>

                                    </div>

                                    <div class="space-6"></div>


                                </div>
                                <div class="profile-contact-info" runat="server">
                                    <div class="profile-contact-links align-left">
                                        <div class="row-fluid">
                                            <div class="span3">Reason</div>
                                            <div class="span9">
                                                <textarea id="txtReason" style="height: 100px; resize: none;" class="span12 limited" data-maxlength="255" maxlength="255"></textarea>
                                            </div>

                                            <%--                       <a class="btn btn-link" href="#" id="btnAdd2">

                                                        <div class="span3">Reason</div>
                                                        &nbsp; 
                                                        <div class="span3">
                                                            <input type="text" style="width: 150px" />
                                                            <textarea id="txtReason" style="height: 120px; resize: none;" class="span12 limited" data-maxlength="255" maxlength="255"></textarea>
                                                        </div>
                                                        
                                                    </a>--%>
                                        </div>
                                    </div>

                                </div>
                                <%--     <div class="row-fluid">
                                                 
                                                <div class="span12">
                                                    <div class="span2 btn btn-link">
                                                        Reason  
                                                            
                                                    </div>
                                                    <div class="span10">
                                                        <input type="text" style="width:165px" />
                                                    </div>

                                                </div>
                                                  
                                            </div>--%>
                            </div>

                            <div class="span9">
                                <div class="center" style="display: none">
                                    <span class="btn btn-app btn-small btn-light no-hover">
                                        <span class="bigger-150 blue">1,411 </span>

                                        <br />
                                        <span class="smaller-90">Views </span>
                                    </span>

                                    <span class="btn btn-app btn-small btn-yellow no-hover">
                                        <span class="bigger-175">32 </span>

                                        <br />
                                        <span class="smaller-90">Followers </span>
                                    </span>

                                    <span class="btn btn-app btn-small btn-pink no-hover">
                                        <span class="bigger-175">4 </span>

                                        <br />
                                        <span class="smaller-90">Projects </span>
                                    </span>

                                    <span class="btn btn-app btn-small btn-grey no-hover">
                                        <span class="bigger-175">23 </span>

                                        <br />
                                        <span class="smaller-90">Reviews </span>
                                    </span>

                                    <span class="btn btn-app btn-small btn-success no-hover">
                                        <span class="bigger-175">7 </span>

                                        <br />
                                        <span class="smaller-90">Albums </span>
                                    </span>

                                    <span class="btn btn-app btn-small btn-primary no-hover">
                                        <span class="bigger-175">55 </span>

                                        <br />
                                        <span class="smaller-90">Contacts </span>
                                    </span>
                                </div>



                                <div class="profile-user-info profile-user-info-striped">
                                    <div class="profile-info-row">
                                        <div class="profile-info-name" style="width: 150px">
                                            Identification Number
                                           
                                        </div>

                                        <div class="profile-info-value" style="margin-left: 160px">
                                            <span id="lblCardNo">&nbsp;</span>&nbsp;

                                        </div>
                                    </div>

                                    <div class="profile-info-row">
                                        <div class="profile-info-name" style="width: 150px">Name Thai</div>

                                        <div class="profile-info-value" style="margin-left: 160px">
                                            <%--   <asp:Label ID="lblNameThai"  Text="&nbsp;"></asp:Label>--%>
                                            <span id="lblNameThai">&nbsp;</span>&nbsp;
                                        </div>
                                    </div>

                                    <div class="profile-info-row">
                                        <div class="profile-info-name" style="width: 150px">Name Eng </div>

                                        <div class="profile-info-value" style="margin-left: 160px">
                                            <%--  <asp:Label ID="lblNameEng" runat="server" Text="&nbsp;"></asp:Label>--%>
                                            <span id="lblNameEng">&nbsp;</span>&nbsp;
                                        </div>
                                    </div>

                                    <div class="profile-info-row">
                                        <div class="profile-info-name" style="width: 150px">Birth Date</div>

                                        <div class="profile-info-value" style="margin-left: 160px">
                                            <%-- <asp:Label ID="lblBirth" runat="server" Text="&nbsp;"></asp:Label>--%>
                                            <span id="lblBirth">&nbsp;</span>&nbsp;
                                        </div>
                                    </div>

                                    <div class="profile-info-row">
                                        <div class="profile-info-name" style="width: 150px">Issue Date</div>

                                        <div class="profile-info-value" style="margin-left: 160px">
                                            <span id="lblIssueDate">&nbsp;</span>&nbsp;
                                                    <%--     <asp:Label ID="lblIssueDate" runat="server" Text="&nbsp;"></asp:Label>--%>
                                        </div>
                                    </div>

                                    <div class="profile-info-row">
                                        <div class="profile-info-name" style="width: 150px">Issue Expiry</div>

                                        <div class="profile-info-value" style="margin-left: 160px">
                                            <span id="lblExpiry">&nbsp;</span>&nbsp;
                                                    <%--   <asp:Label ID="lblExpiry" runat="server" Text="&nbsp;"></asp:Label>--%>
                                        </div>
                                    </div>

                                    <div class="profile-info-row">
                                        <div class="profile-info-name" style="width: 150px">Address</div>

                                        <div class="profile-info-value" style="margin-left: 160px">
                                            <span id="lblAddress">&nbsp;</span>&nbsp;
                                                    <%-- <asp:Label ID="lblAddress" runat="server" Text="&nbsp;"></asp:Label>--%>
                                        </div>
                                    </div>


                                </div>

                                <div class="space-20"></div>

                                <div class="widget-box transparent" runat="server" id="divRecentActivities1">
                                    <div class="widget-header widget-header-small">
                                        <h4 class="blue smaller">
                                            <i class="icon-rss orange"></i>
                                            Recent Activities
                                        </h4>

                                        <div class="widget-toolbar action-buttons">
                                            <a href="#" data-action="reload" onclick="PopulatedataActivity();">
                                                <i class="icon-refresh blue"></i>
                                            </a>

                                            <%--      &nbsp;
													<a href="#" class="pink">
                                                        <i class="icon-trash"></i>
                                                    </a>--%>
                                        </div>
                                    </div>

                                    <div class="widget-body" runat="server" id="divRecentActivities2">
                                        <div class="widget-main padding-8">
                                            <div id="profile-feed-1" class="profile-feed">
                                                <div id="divRecentActivitiesDetail"></div>
                                            </div>
                                        </div>
                                    </div>

                                </div>

                                <%--         <div class="hr hr2 hr-double"></div>

                                <div class="space-6"></div>

                                <div class="center">
                                    <a href="#" class="btn btn-small btn-primary">
                                        <i class="icon-rss bigger-150 middle"></i>

                                        View more activities
												<i class="icon-on-right icon-arrow-right"></i>
                                    </a>
                                </div>--%>
                            </div>
                        </div>
                    </div>



                    <!--PAGE CONTENT ENDS-->
                </div>
                <!--/.span-->
            </div>

            <%--     <div class="profile-user-info profile-user-info-striped">
                                    <div class="profile-info-row">--%>
            <div id="dialog-view" class="profile-user-info profile-user-info-striped" style="display: none">
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

            </div>

        </div>

        <%--   <div class="ace-settings-container" id="ace-settings-container">
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
    </div>

    <input type="hidden" runat="server" id="Hidevalue" value="block" />

    <script type="text/javascript">


        $(document).ready(function () {

            Populatedata();
            PopulatedataActivity();

            $("#btnAdd").on('click', function () {
                onConfirm();

            });

            $("#btnRemove").on('click', function () {
                onConfirmRemove();
            });

            $("#btnBack").on('click', function () {
                var page = getParameterByName('page');
                window.location.href = 'frmBlackList.aspx?page=' + page;
            });

        });


        function Populatedata() {
            var id = getParameterByName('id')
            var param = "{'id':" + JSON.stringify(id) + "}";
            $.ajax({
                type: "POST",
                url: "WebSevice/WebService.asmx/GetVisitorDetailById",
                data: param,
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: function (data) {
                    var strvalue = JSON.parse(data.d);
                    if (strvalue.length == 1) {
                        $("#picavatar").attr("src", 'data:image/jpeg;base64,' + strvalue[0].id_picture);
                        $("#lblUnderImage").text(strvalue[0].fullname_eng);
                        $("#lblCardNo").text(strvalue[0].id_cardno);
                        $("#lblNameThai").text(strvalue[0].fullname_thai);
                        $("#lblNameEng").text(strvalue[0].fullname_eng);
                        $("#lblBirth").text(strvalue[0].birthdate);
                        $("#lblIssueDate").text(strvalue[0].issuedate);
                        $("#lblExpiry").text(strvalue[0].expdate);
                        $("#lblAddress").text(strvalue[0].address);
                        $("#txtReason").text(strvalue[0].reason);
                        if (strvalue[0].is_blacklist == 'Y') {
                            $("#btnAdd").hide();
                            $("#btnRemove").show();
                        } else {
                            $("#btnAdd").show();
                            $("#btnRemove").hide();
                        }
                    } else {
                        $("#lblUnderImage").text('');
                        $("#lblCardNo").text('');
                        $("#lblNameThai").text('');
                        $("#lblNameEng").text(strvalue[0].fullname_eng);
                        $("#lblBirth").text('');
                        $("#lblIssueDate").text('');
                        $("#lblExpiry").text('');
                        $("#lblAddress").text('');
                        $("#txtReason").text('');
                        $("#btnAdd").show();
                        $("#btnRemove").hide();

                    }
                }
            });

        }

        function PopulatedataActivity() {
            var str;
            $activity = $("#divRecentActivitiesDetail");
            var id = getParameterByName('id')
            var param = "{'id':" + JSON.stringify(id) + "}";
            $.ajax({
                type: "POST",
                url: "WebSevice/WebService.asmx/LoadActivityByVisitor",
                data: param,
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: function (data) {
                    var jsonobject = JSON.parse(data.d);
                    $activity.html('');
                    $.each(jsonobject, function (key, val) {

                        str = '           <div class="profile-activity clearfix">'
                            + '               <div>'
                            + '                    <i class="pull-left thumbicon icon-key btn-info no-hover"></i>'
                            + '                        <a class="user" href="#" onclick="onView(' + val.id + ');">To Attend ' + val.room_name + '</a>'
                            + '                <div class="time">'
                            + '                    <i class="icon-time bigger-110"></i>'
                            + '                ' + val.duration + ''
                            + '               </div>'
                            + '            </div>'

                        $activity.append(str);

                    })

                }
            });
        }


        function getParameterByName(name) {
            name = name.replace(/[\[]/, "\\[").replace(/[\]]/, "\\]");
            var regex = new RegExp("[\\?&]" + name + "=([^&#]*)"),
                results = regex.exec(location.search);
            return results === null ? "" : decodeURIComponent(results[1].replace(/\+/g, " "));
        }

        function setcss(value) {
            if (value == '0') {
                $("#btnRemove").hide();
                $("#btnAdd").show();
            } else {
                $("#btnRemove").show();
                $("#btnAdd").hide();
            }
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



        function getParameterByName(name) {
            name = name.replace(/[\[]/, "\\[").replace(/[\]]/, "\\]");
            var regex = new RegExp("[\\?&]" + name + "=([^&#]*)"),
                results = regex.exec(location.search);
            return results === null ? "" : decodeURIComponent(results[1].replace(/\+/g, " "));
        }

        // Confirm
        function onConfirm() {

            var msg = 'Please confirm the add';
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

        function onConfirmRemove() {

            var msg = 'Please confirm the remove';
            var div = $("<div>" + msg + "</div>");
            div.dialog({
                title: "Confirm",
                modal: true,
                buttons: [
                            {
                                text: "Yes",
                                click: function () {
                                    div.dialog("close");
                                    onSaveRemove();
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


        function onSave() {

            var userid = $('#' + '<%=Master.FindControl("lblUserID").ClientID%>').text();
            var id = getParameterByName('id');
            var reason = $('#txtReason').val();
            var param = "{'tb_visitor_id':" + JSON.stringify(id)
                       + ",'reason':" + JSON.stringify(reason)
                       + ",'is_blacklist':" + JSON.stringify('Y')
                       + ",'userid':" + JSON.stringify(userid) + "}";

            $.ajax({
                type: "POST",
                url: "WebSevice/WebService.asmx/InsertOrUpdateReason",
                data: param,
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: onSuccess,
                error: onFailed
            });
        }

        function onSaveRemove() {
            var userid = $('#' + '<%=Master.FindControl("lblUserID").ClientID%>').text();
            var id = getParameterByName('id');
            var reason = $('#txtReason').val();
            var param = "{'tb_visitor_id':" + JSON.stringify(id)
                       + ",'reason':" + JSON.stringify(reason)
                       + ",'is_blacklist':" + JSON.stringify('N')
                       + ",'userid':" + JSON.stringify(userid) + "}";
            $.ajax({
                type: "POST",
                url: "WebSevice/WebService.asmx/InsertOrUpdateReason",
                data: param,
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: onSuccessRemove,
                error: onFailedRemove
            });
        }


        function onSuccess(result) {

            if (result.d == true) {
                onAlert("Add Complete");
                setcss(1);
            } else {
                onAlert("Add Fail");
            }

        }

        function onFailed() {
            onAlert("Add Fail");
        }
        function onSuccessRemove(result) {

            if (result.d == true) {
                onAlert("Remove Complete");
                setcss(0);
            } else {
                onAlert("Remove Fail");
            }

        }

        function onFailedRemove() {
            onAlert("Remove Fail");
        }

        function onView(id) {
            var param = "{'id':" + JSON.stringify(id) + "}";
            $.ajax({
                type: "POST",
                url: "WebSevice/WebService.asmx/LoadActivityDetailByVisitor",
                data: param,
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: function (data) {
                    var strvalue = JSON.parse(data.d);
                    if (strvalue.length == 1) {
                        $("#lblBuildingDesc").text(strvalue[0].building_name);
                        $("#lblFloorDesc").text(strvalue[0].floor);
                        $("#lblRoomDesc").text(strvalue[0].room_name);
                        $("#lblPurposeDesc").text(strvalue[0].purpose);
                        $("#lblDateDesc").text(strvalue[0].strdate);
                    } else {
                        $("#lblBuildingDesc").text("");
                        $("#lblFloorDesc").text("");
                        $("#lblRoomDesc").text("");
                        $("#lblPurposeDesc").text("");
                        $("#lblDateDesc").text("");
                    }
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

        }

    </script>
    <%--    </form>--%>
</asp:Content>

