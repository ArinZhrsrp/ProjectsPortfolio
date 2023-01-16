using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Workshop
{
    public partial class StartUp : Form
    {
        public StartUp()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void btnCustomer_Click(object sender, EventArgs e)
        {
            CustomerLogin cLogin = new CustomerLogin();
            cLogin.Show();
            this.Hide();
        }

        private void btnCafe_Click(object sender, EventArgs e)
        {
            ChefLogin ChefLog = new ChefLogin();
            ChefLog.Show();
            this.Hide();
        }

        private void lblAdmin_Click(object sender, EventArgs e)
        {
            AdminLogin alogin = new AdminLogin();
            alogin.Show();
            this.Hide();

        }
    }
}
