<%@ Page Title="" Language="VB" MasterPageFile="~/ContentMasterPage.master" AutoEventWireup="false" CodeFile="frmReport_Blacklist_Daily.aspx.vb" Inherits="frmReport_Blacklist_Daily" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
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
                    <li class="active">Blacklist report by daily</li>
                </ul>
                <!--.breadcrumb-->

               
                <!--#nav-search-->
            </div>

            <div class="page-content">


                <div class="row-fluid">
                    <div class="span12">
                        <!--PAGE CONTENT BEGINS-->


                        <div class="row-fluid">
                            <h3 class="header smaller lighter blue">Blacklist report by daily</h3>
                          

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
                        
                        <!--/PAGE CONTENT BEGINS-->

                         <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" for="lblName">Name</label>
                            </div>
                            <div class="span4">
                                <%--<select class="chzn-select" id="cbBuilding" data-placeholder="Choose a Building..." runat="server">
                                    <option value="" />
                                    <option value="1">Building 1</option>
                                    <option value="2">Building 2</option>
                                    <option value="3">Building 3</option>
                                    <option value="4">Building 4</option>
                                    <option value="5">Building 5</option>
                                </select>--%>
                                  <input type="text" class="input-mini" id="txtName" style="width: 205px; resize: none;" />
                            </div>
                            <div class="span2">
                                <label class="control-label" for="lblReason">Reason</label>
                            </div>
                            <div class="span4">
                                <%--<select class="chzn-select" id="cbRoomType" data-placeholder="Choose a Room ..." runat="server">
                                    <option value="" />
                                    <option value="1">Meeting Room</option>
                                    <option value="2">Lobby Room</option>
                                    <option value="3">Private room</option>
                                </select>--%>
                                  <input type="text" class="input-mini" id="txtReason" style="width: 205px; resize: none;" />
                            </div>

                        </div>


                         <div class="row-fluid">
                            <div class="span2">
                                <label class="control-label" for="lblMeetingTime">Date From</label>

                            </div>
                            <div class="span4">
                                <div class="row-fluid input-append">
                                    <input class="date-picker" id="datefrom" type="text" data-date-format="dd/mm/yyyy" />
                                    <span class="add-on">
                                        <i class="icon-calendar"></i>
                                    </span>
                                </div>
                      
                            </div>
                             <div class="span2">
                                 <label class="control-label" for="lblMeetingTime">Date To</label>

                             </div>
                             <div class="span4">
                                 <div class="row-fluid input-append">
                                     <input class="date-picker" id="dateto" type="text" data-date-format="dd/mm/yyyy" />
                                     <span class="add-on">
                                         <i class="icon-calendar"></i>
                                     </span>
                                 </div>

                             </div>

                         </div>
                              
                      
                            
                        <div class="row-fluid">
                            <div class="span4">
                                <label class="control-label" for="lblBuilding2"></label>
                            </div>
                            <div class="span8">
                                <button class="btn btn-info" type="button"  id="btnSearch" >
                                    <i class="icon-ok bigger-110"></i>
                                    Preview
                                </button>


                                &nbsp; &nbsp; &nbsp;
									<button class="btn" type="reset" id="btnClear">
                                        <i class="icon-undo bigger-110"></i>
                                        Clear
                                    </button>
                            </div>

                        </div>
                    </div>
                   <div class="row-fluid">
                       <br />
                       <div >
                           <h3 class="header smaller lighter blue">Show Report</h3>
                       </div>
                   </div>
                    <div class="row-fluid">
                          <div class="span12">
                              <button class="btn btn-danger btn-small" type="button" runat="server" id="btnExport" style="display:none">
                                    <i class="icon-reply icon-only"></i>
                                    Export
                                </button>
                          </div>                         
                     </div>

                     <div class="row-fluid">
                         <div class="span12">
                             <br />
                             <div id="divShowTable"></div>
                             <br />
                             <br />
                             <center>
                                        <label id="lbldatanotfound" class="lighter blue" style="font-size:larger;display:none">Data Not Found.</label>
                                    </center>
                             </center>
                         </div>                         
                     </div>


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
            $(function () {

                //Search
                $("#btnSearch").click(function () {
                    populateTable();
                });
                //Export
                $('#' + '<%=btnExport.ClientID%>').click(function () {
                    populateExport();
                });
                $("#btnClear").click(function () {
                    clearInput();
                });

                //ปฎิธิน
                $('.date-picker').datepicker().next().on(ace.click_event, function () {

                    $(this).prev().focus();
                });


            });
        </script>
          <script type="text/javascript">
              function clearInput() {
                  $("#datefrom").val("");
                  $("#dateto").val("");
                  $("#txtName").val("");
                  $("#txtReason").val("");
                  $('#' + '<%=btnExport.ClientID%>').hide();
                $('#divShowTable').hide();
              }

              function populateExport() {
                  var name = $('#txtName').val();
                  var reason = $('#txtReason').val();
                  var strdatefrom = $('#datefrom').val();
                  var strdateto = $('#dateto').val();
                  var para = '?name=' + name + '&reason=' + reason + '&datefrom=' + strdatefrom + '&dateto=' + strdateto;

                  var dataurl = 'frmReport_Blacklist_Daily.ashx' + para;
                  window.location.href = dataurl;
              }

              function populateTable() {
                  var name = $('#txtName').val();
                  var reason = $('#txtReason').val();
                  var strdatefrom = $('#datefrom').val();
                  var strdateto = $('#dateto').val();
                  var param = "{'name':" + JSON.stringify(name)
                              + ",'reason':" + JSON.stringify(reason)
                              + ",'datefrom':" + JSON.stringify(strdatefrom)
                              + ",'dateto':" + JSON.stringify(strdateto) + "}";
                  $table = $("#divShowTable");
                  $.ajax({
                      type: "POST",
                      url: 'WebSevice/WebService.asmx/RenderBlacklistDialy',
                      dataType: 'JSON',
                      data: param,
                      contentType: "application/json; charset=utf-8",
                      success: function (data) {
                          //var jsonobject = JSON.parse(data.d);
                          if (data.d != '') {
                              //clear 
                              $table.html('');
                              $table.append(data.d);
                              $("#lbldatanotfound").hide();
                              $('#divShowTable').show();
                              $('#' + '<%=btnExport.ClientID%>').show();
                        } else {
                            $("#lbldatanotfound").show();
                        }



                    }
                });
            }
              
         </script>
    </form>
</asp:Content>

