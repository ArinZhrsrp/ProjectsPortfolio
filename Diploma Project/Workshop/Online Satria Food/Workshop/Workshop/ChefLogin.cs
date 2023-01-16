using MySql.Data.MySqlClient;
using System;
using System.Windows.Forms;

namespace Workshop
{
    public partial class ChefLogin : Form
    {
        public ChefLogin()
        {
            InitializeComponent();
        }

        private void btnRegister_Click(object sender, EventArgs e)
        {


        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            txtboxUname.Text = "";
            txtBoxPass.Text = "";
        }

        private void btnBack_Click(object sender, EventArgs e)
        {
            
        }

        private void btnLogin_Click(object sender, EventArgs e)
        {
            string name = txtboxUname.Text;
            string password = txtBoxPass.Text;

            string queryRegister = $"SELECT * FROM `chef`";
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
                            if (name == myReader.GetString(1) && password == myReader.GetString(2))
                            {
                                string id = myReader.GetString(0);
                                ChefSite cSite = new ChefSite(id);
                                cSite.Show();
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

        private void label1_Click(object sender, EventArgs e)
        {
            StartUp stUp = new StartUp();
            stUp.Show();
            this.Hide();
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            chefRegister creg = new chefRegister();
            creg.Show();
            this.Hide();
        }
    }
}
