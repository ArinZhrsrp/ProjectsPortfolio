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
    public partial class AdminLogin : Form
    {
        public AdminLogin()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            txtusername.Text = "";
            txtpass.Text = "";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            StartUp sup = new StartUp();
            sup.Show();
            this.Hide();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string username = txtusername.Text;
            string password = txtpass.Text;

            string queryRegister = $"SELECT * FROM `admin` ";
            string mySqlConnection = "datasource=127.0.0.1;port=3306;username=root;password=;database=online_satria_food";

            MySqlConnection databaseConnection = new MySqlConnection(mySqlConnection);
            MySqlCommand commandDatabase = new MySqlCommand(queryRegister, databaseConnection);

            try
            {
                databaseConnection.Open();
                MySqlDataReader myReader = commandDatabase.ExecuteReader();
                while (true)
                {
                    if (myReader.HasRows)
                    {
                        while (myReader.Read())
                        {
                            if (username == myReader.GetString(1) && password == myReader.GetString(2))
                            {
                                AdminSite asite = new AdminSite();
                                asite.Show();
                                this.Hide();
                                goto x;
                            }
                        }
                    }
                    MessageBox.Show("Wrong combination of username and Password");
                x:
                    break;
                }

            }
            catch (Exception except)
            {
                MessageBox.Show("Error Occured" + except);
            }
        }
    }
}
