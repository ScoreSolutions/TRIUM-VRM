<%@ Page Title="" Language="VB" MasterPageFile="~/ContentMasterPage.master" AutoEventWireup="false" CodeFile="frmReport_Booking_Daily.aspx.vb" Inherits="frmReport_Booking_Daily" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="Server">
    <form id="form1" runat="server">

        <asp:ScriptManager ID="ScriptManager1" runat="server"></asp:ScriptManager>
        <asp:UpdatePanel ID="UpdatePanel1" runat="server">
            <ContentTemplate>
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
                            <li class="active">Booking meeting room report by daily</li>
                        </ul>
                        <!--.breadcrumb-->


                        <!--#nav-search-->
                    </div>

                    <div class="page-content">


                        <div class="row-fluid">
                            <div class="span12">
                                <!--PAGE CONTENT BEGINS-->


                                <div class="row-fluid">
                                    <h3 class="header smaller lighter blue">Booking meeting room report by daily</h3>


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
                                        <label class="control-label" for="lblBuilding">Building</label> 
                                    </div>
                                    <div class="span4">
                                        <select class="chzn-select" id="cbBuilding" >
                                        </select>
                                    </div>
                                    <div class="span2">
                                        <label class="control-label" for="lblRoomType">Room</label>
                                    </div>
                                    <div class="span4">
                                        <select class="chzn-select" id="cbRoom">
                                        </select>

                                    </div>


                                </div>
                                <div class="space-2"></div>

                                <div class="row-fluid">
                                    <div class="span2">
                                        <label class="control-label" for="lblMeetingTime">Date From</label>

                                    </div>
                                    <div class="span4">
                                        <div class="row-fluid input-append">
                                            <input class="date-picker" id="datefrom" type="text" data-date-format="dd/mm/yyyy"/>
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
                                            <input class="date-picker" id="dateto" type="text" data-date-format="dd/mm/yyyy"  />
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
                                        <button class="btn btn-info" type="button" id="btnSearch" >
                                            <i class="icon-ok bigger-110"></i>
                                            Preview
                                        </button>


                                        &nbsp; &nbsp; &nbsp;
									<button class="btn" type="reset"  id="btnClear" >
                                        <i class="icon-undo bigger-110"></i>
                                        Clear
                                    </button>
                                    </div>

                                </div>
                            </div>
                            <div class="row-fluid">
                                <br />
                                <div>
                                    <h3 class="header smaller lighter blue">Show Report</h3>
                                </div>
                            </div>
                            <div class="row-fluid">
                                <div class="span12">
                  
                                                   <button class="btn btn-danger btn-small" type="button" runat="server"  id="btnExport" style="display:none" >
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

                 
                    </div>--%>
                    <!--/#ace-settings-container-->
                </div>

            </ContentTemplate>
        </asp:UpdatePanel>



        <script type="text/javascript">
            $(function () {
                //Populate
                populateSelect();


                $('#cbBuilding').change(function () { 
                    populateSelectRoom();
                });

                $('#cbRoom').change(function () {
                    populateSelectBuilding();
                });

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
                $('#' + '<%=btnExport.ClientID%>').hide();
                $('#divShowTable').hide();
                populateSelect();
            }
            function populateExport() {
                    var buildingid = $('#cbBuilding').val();
                    var roomid = $('#cbRoom').val();
                    var strdatefrom = $('#datefrom').val();
                    var strdateto = $('#dateto').val();
                    var para = '?buildingid=' + buildingid + '&roomid=' + roomid + '&datefrom=' + strdatefrom + '&dateto=' + strdateto;

                    var dataurl = 'frmReport_Booking_Daily.ashx' + para;
                    window.location.href = dataurl;                   
            }

            function populateTable() {
                var buildingid = $('#cbBuilding').val();
                var roomid = $('#cbRoom').val();
                var strdatefrom = $('#datefrom').val();
                var strdateto = $('#dateto').val();
                var param = "{'buildingid':" + JSON.stringify(buildingid)
                            + ",'roomid':" + JSON.stringify(roomid)
                            + ",'datefrom':" + JSON.stringify(strdatefrom)
                            + ",'dateto':" + JSON.stringify(strdateto) + "}";
                $table = $("#divShowTable");
                $.ajax({
                    type: "POST",
                    url: 'WebSevice/WebService.asmx/RenderBookingDialy',
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
                        $selectRoom.append('<option value="">Choose all</option>');
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

            function populateSelectBuilding() {
                var strselect;
                var id = $('#cbRoom').val();
                var param = "{'id':" + JSON.stringify(id) + "}";
                $selectBuilding = $("#cbBuilding");
                var id_building_selected = $selectBuilding.val();
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
                        $selectBuilding.append('<option value="">Choose all</option>');
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

            function populateSelect() {
                        $selectRoom = $('#cbRoom');
                      //$selectRoom = $("#cbRoom");
                      $.ajax({
                          type: "POST",
                          url: 'WebSevice/WebService.asmx/LoadActiveRoom',
                          dataType: 'JSON',
                          contentType: "application/json; charset=utf-8",
                          success: function (data) {
                              var jsonobject = JSON.parse(data.d);

                              //clear 
                              $selectRoom.html('');
                              $selectRoom.append('<option value="">Choose all</option>');
                              //append a select option
                              $.each(jsonobject, function (key, val) {
                                  // alert(val.id + '' + val.room_name);
                                  $selectRoom.append('<option value="' + val.id + '">' + val.room_name + '</option>');
                                  $selectRoom.trigger("liszt:updated");//update select option
                              })
                          }
                      });

                      $selectBuilding = $("#cbBuilding");
                      $.ajax({
                          type: "POST",
                          url: 'WebSevice/WebService.asmx/LoadActiveBuliding',
                          dataType: 'JSON',
                          contentType: "application/json; charset=utf-8",
                          success: function (data) {
                              var jsonobject = JSON.parse(data.d);
                              //clear 
                              $selectBuilding.html('');
                              $selectBuilding.append('<option value="">Choose all</option>');
                              //append a select option
                              $.each(jsonobject, function (key, val) {

                                  $selectBuilding.append('<option value="' + val.id + '">' + val.building_name + '</option>');
                                  $selectBuilding.trigger("liszt:updated");//update select option
                              })
                          }
                      });

                      //Combo Box  
                      $(".chzn-select").chosen();
                  }
        </script>

        <style>
            /*div {
                    width: 100%;
                }*/

            .success {
                background-color: #ccffcc;
            }
        </style>
    </form>
</asp:Content>

