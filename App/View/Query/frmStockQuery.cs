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
    public partial class frmStockQuery : BaseForm
    {
        BLL.BLLBase bll = new BLL.BLLBase();

        public frmStockQuery()
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
            string Comd = "WMS.SelectProductDetailQuery";
            if (this.rbtDetail.Checked)
            {
                this.colCellCode.Visible = true;
                this.colCellName.Visible = true ;
                this.colPalletBarCode.Visible = true;
                Comd = "WMS.SelectProductDetailQuery";
            }
            else
            {
                this.colCellCode.Visible = false;
                this.colCellName.Visible = false;
                this.colPalletBarCode.Visible = false;
                Comd = "WMS.SelectProductTotalQuery";
            }
            string StrWhere = "1=1 ";
            if (cmbCategoryCode.SelectedValue.ToString() != "请选择")
            {
                StrWhere += string.Format(" and CategoryCode='{0}'", cmbCategoryCode.SelectedValue.ToString());
            }
            if (this.txtProductCode.Text.Trim() != "")
            {
                StrWhere += string.Format(" and ( ProductCode like '%{0}%' or ProductName like '%{0}%')", this.txtProductCode.Text.Trim());
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
            string FileName = "现有库存明细表";
            if (!rbtDetail.Checked)
                FileName = "现有库存统计表";
            Common.ExportToExcel ete = new Common.ExportToExcel();
            ete.OutputAsExcelFile(this.dgvMain, FileName);
            
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
