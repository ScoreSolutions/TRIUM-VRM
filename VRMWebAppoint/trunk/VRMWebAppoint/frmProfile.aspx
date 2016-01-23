<%@ Page Language="VB" AutoEventWireup="false" CodeFile="frmProfile.aspx.vb" Inherits="frmProfile" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <meta charset="utf-8" />
    <title>User Profile Page - Ace Admin</title>

    <meta name="description" content="3 styles with inline editable feature" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />

    <!--basic styles-->

    <link href="assets/css/bootstrap.min.css" rel="stylesheet" />
    <link href="assets/css/bootstrap-responsive.min.css" rel="stylesheet" />
    <link rel="stylesheet" href="assets/css/font-awesome.min.css" />

    <!--[if IE 7]>
		  <link rel="stylesheet" href="assets/css/font-awesome-ie7.min.css" />
		<![endif]-->

    <!--page specific plugin styles-->

    <link rel="stylesheet" href="assets/css/jquery-ui-1.10.3.custom.min.css" />
    <link rel="stylesheet" href="assets/css/jquery.gritter.css" />
    <link rel="stylesheet" href="assets/css/select2.css" />
    <link rel="stylesheet" href="assets/css/bootstrap-editable.css" />

    <!--fonts-->

    <link rel="stylesheet" href="http://fonts.googleapis.com/css?family=Open+Sans:400,300" />

    <!--ace styles-->

    <link rel="stylesheet" href="assets/css/ace.min.css" />
    <link rel="stylesheet" href="assets/css/ace-responsive.min.css" />
    <link rel="stylesheet" href="assets/css/ace-skins.min.css" />

    <!--[if lte IE 8]>
		  <link rel="stylesheet" href="assets/css/ace-ie.min.css" />
		<![endif]-->

    <!--inline styles related to this page-->
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
</head>
<body>
    <form id="form1" runat="server">
        <div class="page-content">
            <div class="page-header position-relative" runat="server" id="divHeader" style="display: none">
                <h1>User Profile 
                </h1>
            </div>
            <!--/.page-header-->

            <div class="row-fluid">
                <div class="span12">
                    <!--PAGE CONTENT BEGINS-->




                    <div>
                        <div id="user-profile-1" class="user-profile row-fluid">
                            <div class="span3 center">
                                <div>
                                    <span class="profile-picture" style="height:225px;width:200px;">
                                    <%--                                        <img id="avatar" class="editable" alt="Alex's Avatar" src="assets/avatars/profile-pic.jpg" />--%>
                                        <img runat="server" id="picavatar"  alt="" src="assets/avatars/profile-pic.jpg"  style="height:225px;width:200px;" />

                                    </span>

                                    <div class="space-4"></div>

                                    <div class="width-80 label label-info label-large arrowed-in arrowed-in-right">
                                        <div class="inline position-relative">
                                            <a href="#" class="user-title-label dropdown-toggle" data-toggle="dropdown">
                                            <%-- <i class="icon-circle light-green middle"></i>
                                                &nbsp;--%>
                                                <span runat="server" id="lblUnderImage" class="white middle bigger-120"></span>
                                            </a>

                                            <%--<ul class="align-left dropdown-menu dropdown-caret dropdown-lighter">
                                                <li class="nav-header">Change Status </li>

                                                <li>
                                                    <a href="#">
                                                        <i class="icon-circle green"></i>
                                                        &nbsp;
																<span class="green">Available</span>
                                                    </a>
                                                </li>

                                                <li>
                                                    <a href="#">
                                                        <i class="icon-circle red"></i>
                                                        &nbsp;
																<span class="red">Busy</span>
                                                    </a>
                                                </li>

                                                <li>
                                                    <a href="#">
                                                        <i class="icon-circle grey"></i>
                                                        &nbsp;
																<span class="grey">Invisible</span>
                                                    </a>
                                                </li>
                                            </ul>--%>
                                        </div>
                                    </div>
                                </div>

                                <div class="space-6"></div>

                                <div class="profile-contact-info" runat="server" id="divAddBlackList" >
                                    <div class="profile-contact-links align-left">
                                        <a class="btn btn-link" href="#" id="btnAdd">
                                            <i class="icon-plus-sign bigger-120 green"></i>
                                            Add as a Black list
                                        </a>

                                        <a class="btn btn-link" href="#" style="display: none">
                                            <i class="icon-envelope bigger-120 pink"></i>
                                            Send a message
                                        </a>


                                    </div>

                                    <div class="space-6"></div>


                                </div>


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
                                            <%--<span class="editable" id="username">alexdoe</span>--%>
                                            <asp:Label ID="lblCardNo" runat="server" Text="&nbsp;"></asp:Label>
                                        </div>
                                    </div>

                                    <div class="profile-info-row">
                                        <div class="profile-info-name" style="width: 150px">Name Thai</div>

                                        <div class="profile-info-value" style="margin-left: 160px">
                                            <asp:Label ID="lblNameThai" runat="server" Text="&nbsp;"></asp:Label>
                                        </div>
                                    </div>

                                    <div class="profile-info-row">
                                        <div class="profile-info-name" style="width: 150px">Name Eng </div>

                                        <div class="profile-info-value" style="margin-left: 160px">
                                            <asp:Label ID="lblNameEng" runat="server" Text="&nbsp;"></asp:Label>
                                        </div>
                                    </div>

                                    <div class="profile-info-row">
                                        <div class="profile-info-name" style="width: 150px">Birth Date</div>

                                        <div class="profile-info-value" style="margin-left: 160px">
                                            <asp:Label ID="lblBirth" runat="server" Text="&nbsp;"></asp:Label>
                                        </div>
                                    </div>

                                    <div class="profile-info-row">
                                        <div class="profile-info-name" style="width: 150px">Issue Date</div>

                                        <div class="profile-info-value" style="margin-left: 160px">
                                            <asp:Label ID="lblIssueDate" runat="server" Text="&nbsp;"></asp:Label>
                                        </div>
                                    </div>

                                    <div class="profile-info-row">
                                        <div class="profile-info-name" style="width: 150px">Issue Expiry</div>

                                        <div class="profile-info-value" style="margin-left: 160px">
                                            <asp:Label ID="lblExpiry" runat="server" Text="&nbsp;"></asp:Label>
                                        </div>
                                    </div>

                                    <div class="profile-info-row">
                                        <div class="profile-info-name" style="width: 150px">Address</div>

                                        <div class="profile-info-value" style="margin-left: 160px">
                                            <asp:Label ID="lblAddress" runat="server" Text="&nbsp;"></asp:Label>
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
                                            <a href="#" data-action="reload">
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
                                                <div class="profile-activity clearfix">
                                                    <div>
                                                        <%--                                                        <img class="pull-left" alt="Alex Doe's avatar" src="assets/avatars/avatar5.png" />--%>
                                                        <i class="pull-left thumbicon icon-key btn-info no-hover"></i>
                                                        <a class="user" href="#">มาประชุมที่ห้องประชุม 1 </a>
                                                        <div class="time">
                                                            <i class="icon-time bigger-110"></i>
                                                            10 day ago
                                                        </div>
                                                    </div>


                                                </div>
                                                <div class="profile-activity clearfix">
                                                    <div>
                                                        <%--                                                        <img class="pull-left" alt="Alex Doe's avatar" src="assets/avatars/avatar5.png" />--%>
                                                        <i class="pull-left thumbicon icon-key btn-info no-hover"></i>
                                                        <a class="user" href="#">มาประชุมที่ห้องประชุม 2 </a>
                                                        <div class="time">
                                                            <i class="icon-time bigger-110"></i>
                                                            12 day ago
                                                        </div>
                                                    </div>


                                                </div>
                                                <div class="profile-activity clearfix">
                                                    <div>
                                                        <%--                                                        <img class="pull-left" alt="Alex Doe's avatar" src="assets/avatars/avatar5.png" />--%>
                                                        <i class="pull-left thumbicon icon-key btn-info no-hover"></i>
                                                        <a class="user" href="#">มาประชุมที่ห้องประชุม 3 </a>
                                                        <div class="time">
                                                            <i class="icon-time bigger-110"></i>
                                                            15 day ago
                                                        </div>
                                                    </div>


                                                </div>
                                                <div class="profile-activity clearfix">
                                                    <div>
                                                        <%--                                                        <img class="pull-left" alt="Alex Doe's avatar" src="assets/avatars/avatar5.png" />--%>
                                                        <i class="pull-left thumbicon icon-key btn-info no-hover"></i>
                                                        <a class="user" href="#">มาประชุมที่ห้องประชุม 4 </a>
                                                        <div class="time">
                                                            <i class="icon-time bigger-110"></i>
                                                            17day ago
                                                        </div>
                                                    </div>


                                                </div>

                                                <div class="profile-activity clearfix">
                                                    <div>
                                                        <%--                                                        <img class="pull-left" alt="Alex Doe's avatar" src="assets/avatars/avatar5.png" />--%>
                                                        <i class="pull-left thumbicon icon-key btn-info no-hover"></i>
                                                        <a class="user" href="#">มาประชุมที่ห้องประชุม 5 </a>
                                                        <div class="time">
                                                            <i class="icon-time bigger-110"></i>
                                                            19 day ago
                                                        </div>
                                                    </div>


                                                </div>


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
            <!--/.row-fluid-->
        </div>
        <!--/.page-content-->
    </form>











    <script src="http://ajax.googleapis.com/ajax/libs/jquery/2.0.3/jquery.min.js"></script>

    <!--<![endif]-->

    <!--[if IE]>
<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js"></script>
<![endif]-->

    <!--[if !IE]>-->

    <script type="text/javascript">
        window.jQuery || document.write("<script src='assets/js/jquery-2.0.3.min.js'>" + "<" + "/script>");
    </script>

    <!--<![endif]-->

    <!--[if IE]>
<script type="text/javascript">
 window.jQuery || document.write("<script src='assets/js/jquery-1.10.2.min.js'>"+"<"+"/script>");
</script>
<![endif]-->

    <script type="text/javascript">
        if ("ontouchend" in document) document.write("<script src='assets/js/jquery.mobile.custom.min.js'>" + "<" + "/script>");
    </script>
    <script src="assets/js/bootstrap.min.js"></script>

    <!--page specific plugin scripts-->

    <!--[if lte IE 8]>
		  <script src="assets/js/excanvas.min.js"></script>
		<![endif]-->

    <script src="assets/js/jquery-ui-1.10.3.custom.min.js"></script>
    <script src="assets/js/jquery.ui.touch-punch.min.js"></script>
    <script src="assets/js/jquery.gritter.min.js"></script>
    <script src="assets/js/bootbox.min.js"></script>
    <script src="assets/js/jquery.slimscroll.min.js"></script>
    <script src="assets/js/jquery.easy-pie-chart.min.js"></script>
    <script src="assets/js/jquery.hotkeys.min.js"></script>
    <script src="assets/js/bootstrap-wysiwyg.min.js"></script>
    <script src="assets/js/select2.min.js"></script>
    <script src="assets/js/date-time/bootstrap-datepicker.min.js"></script>
    <script src="assets/js/fuelux/fuelux.spinner.min.js"></script>
    <script src="assets/js/x-editable/bootstrap-editable.min.js"></script>
    <script src="assets/js/x-editable/ace-editable.min.js"></script>
    <script src="assets/js/jquery.maskedinput.min.js"></script>

    <!--ace scripts-->

    <script src="assets/js/ace-elements.min.js"></script>
    <script src="assets/js/ace.min.js"></script>

    <!--inline scripts related to this page-->

    <script type="text/javascript">

        // Standard Dialogs
        $("#btnAdd").on('click', function () {
            //reset();
            //alertify.alert("This is an alert dialog");
            //return false;

            //reset();
            //alertify.success("Success log message");
            //return false;
            onAlert(122343545465);
           
        });

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

        
        function onSave() {
           <%-- var strTemp = $("#<%= txtKeepId.ClientID%>").val();--%>

            var strTemp = getParameterByName('id');

            var param = "{'strID':" + JSON.stringify(strTemp) + "}";
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

    </script>
</body>
</html>
