using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Reflection;
using System.IO;
using Neurotec;
using Neurotec.Diagnostics;

namespace Neurotec.Tutorials
{
	public partial class MainForm : Form
	{
		public MainForm()
		{
			InitializeComponent();
		}

		private void btnClose_Click(object sender, EventArgs e)
		{
			this.Close();
		}

		private void fillProducts()
		{
			cbProducts.Items.Clear();

			foreach (FieldInfo fInfo in ((object)new DiagnosticAPIProductId()).GetType().GetFields(BindingFlags.Public | BindingFlags.Static))
			{
				cbProducts.Items.Add(fInfo.Name);
			}
		}

		private void MainForm_Load(object sender, EventArgs e)
		{
			fillProducts();
			cbProducts.SelectedIndex = 0;
		}

		private void btnGenerate_Click(object sender, EventArgs e)
		{
			richTextBox1.Clear();
			richTextBox1.AppendText(DiagnosticsAPI.GetGeneralInfo() + "\n" +
				"Program location: " + System.Windows.Forms.Application.StartupPath + "\n\n");

			//str += readLicFile(paramName, licFile);
			richTextBox1.AppendText(DiagnosticsAPI.GetRunningPgInfo() + "\n" +
					DiagnosticsAPI.GetInstalledRuntimesInfo() + "\n");

			richTextBox1.AppendText("Trial server test: " + DiagnosticsAPI.TestTrialServerHttp() + '\n' +
				"Trial server (sockets) test: " + DiagnosticsAPI.TestTrialServerSockets() + '\n' +
				"Trial time left: " + DiagnosticsAPI.GetTrialTimeLeft() + "\n");

			string selecteditem2 = cbProducts.Items[cbProducts.SelectedIndex].ToString();
			FieldInfo fInfo2 = ((object)new DiagnosticAPIProductId()).GetType().GetField(selecteditem2);
			DiagnosticAPIProductId productID2 = (DiagnosticAPIProductId)fInfo2.GetRawConstantValue();

			if (!Directory.Exists(textBoxPath.Text) && textBoxPath.Text != string.Empty && textBoxPath.Text != "null")
			{
				richTextBox1.SelectionColor = Color.Red;
				richTextBox1.SelectionFont = new Font("Courier New", 10, FontStyle.Bold);

				richTextBox1.SelectedText = "Error! directory '" + textBoxPath.Text + "' does not exist\n\r";

			}

			richTextBox1.AppendText(DiagnosticsAPI.GetRegisteredComponents(productID2, textBoxPath.Text) + "\n");

			if (productID2 == DiagnosticAPIProductId.VeriFinger)
			{
				richTextBox1.AppendText(DiagnosticsAPI.GetComLibsAndFPSmmContents(textBoxPath.Text) + "\n" +
					"Path: " + Environment.GetEnvironmentVariable("PATH") + "\n");
			}
		}

		private void buttonPath_Click(object sender, EventArgs e)
		{
			folderBrowserDialog.SelectedPath = textBoxPath.Text;
			if (folderBrowserDialog.ShowDialog() == DialogResult.OK)
			{
				textBoxPath.Text = folderBrowserDialog.SelectedPath;
			}
		}
	}
}
