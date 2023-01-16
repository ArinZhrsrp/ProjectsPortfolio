using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data.MySqlClient;

namespace Workshop
{
    public partial class CustomerRegister : Form
    {
        //string no_matric3 = = 
        //public static string no_matric2
        //txtBoxMatricNo.Text;
        public CustomerRegister()
        {
            InitializeComponent();
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            txtBoxMatricNo.Text = "";
            txtBoxPass.Text = "";
            txtBoxPhoneNo.Text = "";
            txtBoxUName.Text = "";
        }

        private void btnRegister_Click(object sender, EventArgs e)
        {
            runQuery();
            CustomerLogin cLogin = new CustomerLogin();
            cLogin.Show();
            this.Hide();
        }

        private void runQuery() 
        {
            String no_matric = txtBoxMatricNo.Text;
            String Name = txtBoxUName.Text;
            String password = txtBoxPass.Text;
            String hp_no = txtBoxPhoneNo.Text;
            string queryRegister = $"INSERT INTO `customers`(`no_matric`, `c_name`, `c_password`, `c_phone_no`) VALUES ('{no_matric}','{Name}','{password}','{hp_no}')";

            string mySqlConnection = "datasource=127.0.0.1;port=3306;username=root;password=;database=online_satria_food";

            MySqlConnection databaseConnection = new MySqlConnection(mySqlConnection);

            MySqlCommand commandDatabase = new MySqlCommand(queryRegister, databaseConnection);

            try
            {
                databaseConnection.Open();

                MySqlDataReader myReader = commandDatabase.ExecuteReader();

                MessageBox.Show("Successfully Register New Account");
            }
            catch (Exception except)
            {
                MessageBox.Show("Error While Registering New User or Already Register This Account" + except.Message);
            }
     
        }

        private void CustomerRegister_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {
            CustomerLogin clogin = new CustomerLogin();
            clogin.Show();
            this.Hide();
        }
    }
}
