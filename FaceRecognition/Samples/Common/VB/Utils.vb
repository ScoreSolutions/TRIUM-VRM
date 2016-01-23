Imports Microsoft.VisualBasic
Imports System
Imports System.Globalization
Imports System.Reflection
Imports System.Diagnostics
Imports System.Collections.Generic
Imports System.IO

#If Not N_PRODUCT_HAS_NO_LICENSES Then
Imports Neurotec.Licensing
#End If

Friend NotInheritable Class Utils
	Private Sub New()
	End Sub

	Public Shared Sub PrintTutorialHeader(ByVal args As String())
		Dim description As String = (CType(Assembly.GetExecutingAssembly().GetCustomAttributes(GetType(AssemblyDescriptionAttribute), False)(0), AssemblyDescriptionAttribute)).Description
		Dim version As String = FileVersionInfo.GetVersionInfo(Assembly.GetExecutingAssembly().Location).FileVersion
		Dim copyright As String = (CType(Assembly.GetExecutingAssembly().GetCustomAttributes(GetType(AssemblyCopyrightAttribute), False)(0), AssemblyCopyrightAttribute)).Copyright
		Console.WriteLine("")
		Console.WriteLine("{0} (Version: {1})", description, version)
		Console.WriteLine(copyright.Replace("?", "(C)"))
		Console.WriteLine()
		If args IsNot Nothing AndAlso args.Length > 0 Then
			Console.WriteLine("Arguments:")
			For Each item As String In args
				Console.WriteLine(vbTab + "{0}", item)
			Next
			Console.WriteLine()
		End If
	End Sub

	Public Shared Sub ObtainLicenses(ByVal component As String)
		ObtainLicenses(New List(Of String)(New String() {component}))
	End Sub
	Public Shared Sub ObtainLicenses(ByVal components As IList(Of String))
#If Not N_PRODUCT_HAS_NO_LICENSES Then
		For Each component As String In components
			Try
				Dim available As Boolean = NLicense.ObtainComponents("/local", "5000", component)

				If (Not available) Then
					Throw New Exception(String.Format("license for {0} was not obtained", component))
				End If
			Catch ex As Exception
				Throw New Exception(String.Format("Error while obtaining license. Please check if Neurotec Activation Service is running. Details: {0}", ex))
			End Try
		Next
#End If
	End Sub

	Public Shared Sub ReleaseLicenses(ByVal components As IList(Of String))
#If Not N_PRODUCT_HAS_NO_LICENSES Then
		For Each component As String In components
			Try
				NLicense.ReleaseComponents(component)
			Catch ex As Exception
			End Try
		Next
#End If
	End Sub
	Public Shared Function GetAssemblyName() As String
		Return (Assembly.GetExecutingAssembly().GetName().Name)
	End Function
	Public Shared Function GetAssemblyPath() As String
		Return (Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location))
	End Function
	Public Shared Function QualityToPercent(ByVal value As Byte) As Integer
		Return CInt((2 * value * 100 + 255) / (2 * 255))
	End Function
	Public Shared Function QualityFromPercent(ByVal value As Integer) As Byte
		Return CByte(Fix((2 * value * 255 + 100) / (2 * 100)) Mod 256)
	End Function
	Public Shared Function MatchingThresholdToString(ByVal value As Integer) As String
		Dim p As Double = -value / 12.0
		Return String.Format(String.Format("{{0:P{0}}}", Math.Max(0, CInt(Fix(Math.Ceiling(-p))) - 2)), Math.Pow(10, p))
	End Function
	Public Shared Function MatchingThresholdFromString(ByVal value As String) As Integer
		Dim p As Double = Math.Log10(Math.Max(Double.Epsilon, Math.Min(1, Double.Parse(value.Replace(CultureInfo.CurrentCulture.NumberFormat.PercentSymbol, "")) / 100)))
		Return Math.Max(0, CInt(Fix(Math.Round(-12 * p))))
	End Function
	Public Shared Function MaximalRotationToDegrees(ByVal value As Byte) As Integer
		Return CInt((2 * value * 360 + 256) / (2 * 256))
	End Function
	Public Shared Function MaximalRotationFromDegrees(ByVal value As Integer) As Byte
		Return CByte((2 * value * 256 + 360) / (2 * 360))
	End Function
	Public Shared Function GetUserLocalDataDir(ByVal productName As String) As String
		Dim localDataDir As String = Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData)
		localDataDir = Path.Combine(localDataDir, "Neurotechnology")
		If (Not Directory.Exists(localDataDir)) Then
			Directory.CreateDirectory(localDataDir)
		End If
		localDataDir = Path.Combine(localDataDir, productName)
		If (Not Directory.Exists(localDataDir)) Then
			Directory.CreateDirectory(localDataDir)
		End If

		Return localDataDir
	End Function
End Class
