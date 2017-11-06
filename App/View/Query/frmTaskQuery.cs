﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Util;
using DataGridViewAutoFilter;

namespace App.View.Query
{
    public partial class frmTaskQuery : BaseForm
    {
        BLL.BLLBase bll = new BLL.BLLBase();

        public frmTaskQuery()
        {
            InitializeComponent();
        }

        
    

      
        private void frmStockQuery_Shown(object sender, EventArgs e)
        {
            for (int i = 0; i < this.dgvMain.Columns.Count - 1; i++)
                if (this.dgvMain.Columns[i].DataPropertyName.ToLower().IndexOf("date") == -1)
                ((DataGridViewAutoFilterTextBoxColumn)this.dgvMain.Columns[i]).FilteringEnabled = true;

            BindDropDown();
        }
        private void BindDropDown()
        {
            DataTable dt = bll.FillDataTable("CMD.SelectProductCategory");
            DataRow dr = dt.NewRow();
            dr["CategoryCode"] = "";
            dr["CategoryCode"] = "请选择";
            dt.Rows.InsertAt(dr, 0);
            dt.AcceptChanges();
            this.cmbCategoryCode.DisplayMember = "CategoryCode";
            this.cmbCategoryCode.ValueMember = "CategoryCode";
            this.cmbCategoryCode.DataSource = dt;


        }

        private void btnQuery_Click(object sender, EventArgs e)
        {
            string Comd = "WMS.SelectTaskQuery";
             

            string StrWhere = "1=1 ";
            if (rbtInStcok.Checked)
            {
                StrWhere += " and Task.TaskType='11' ";
            }
            else if(rbtOutStock.Checked)
            {
                StrWhere += " and Task.TaskType in ('12','15') ";
            }
            else if (rbtInvonter.Checked)
            {
                StrWhere += " and Task.TaskType='14'";
            }
            if (!chk1.Checked)
                StrWhere += " Task.ProductCode!='' ";

            if (cmbCategoryCode.SelectedValue.ToString() != "请选择")
            {
                StrWhere += string.Format(" and CategoryCode='{0}'", cmbCategoryCode.SelectedValue.ToString());
            }
            if (this.txtProductCode.Text.Trim() != "")
            {
                StrWhere += string.Format(" and ( Task.roductCode like '%{0}%' or ProductName like '%{0}%')", this.txtProductCode.Text.Trim());
            }
            if (this.txtSpec.Text.Trim() != "")
            {
                StrWhere += string.Format(" and Spec like '%{0}%'", this.txtSpec.Text.Trim());
            }

            DataTable dt = bll.FillDataTable(Comd, new DataParameter[] { new DataParameter("{0}", StrWhere) });
            bsMain.DataSource = dt;

        }

        private void btnExPort_Click(object sender, EventArgs e)
        {
            string FileName = "任务查询";
            Common.ExportToExcel ete = new Common.ExportToExcel();
            ete.OutputAsExcelFile(this.dgvMain, FileName);
            
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
