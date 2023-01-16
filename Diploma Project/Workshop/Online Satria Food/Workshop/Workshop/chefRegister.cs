using MySql.Data.MySqlClient;
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
    public partial class chefRegister : Form
    {
        public chefRegister()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ChefLogin clogin = new ChefLogin();
            clogin.Show();
            this.Hide();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            txtid.Text = "";
            txtname.Text = "";
            txtpass.Text = "";
            txtphone.Text = "";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string id = txtid.Text;
            string Name = txtname.Text;
            string password = txtpass.Text;
            string hp_no = txtphone.Text;
            int id2 = Int32.Parse(id);

            string queryRegister = $"INSERT INTO `chef`(`chef_ID`, `Name`, `password`, `Phone`) VALUES ('{id2}','{Name}','{password}','{hp_no}')";
            string mySqlConnection = "datasource=127.0.0.1;port=3306;username=root;password=;database=online_satria_food";
            MySqlConnection databaseConnection = new MySqlConnection(mySqlConnection);
            MySqlCommand commandDatabase = new MySqlCommand(queryRegister, databaseConnection);

            try
            {
                databaseConnection.Open();

                MySqlDataReader myReader = commandDatabase.ExecuteReader();

                MessageBox.Show("Successfully Register New Account");
                txtid.Text = "";
                txtname.Text = "";
                txtpass.Text = "";
                txtphone.Text = "";
            }
            catch (Exception except)
            {
                MessageBox.Show("Error While Registering New User or Already Register This Account" + except.Message);
            }
        }
    }
}
