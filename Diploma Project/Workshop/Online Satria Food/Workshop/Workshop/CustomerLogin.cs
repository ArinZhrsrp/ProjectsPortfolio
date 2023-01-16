using MySql.Data.MySqlClient;
using System;
using System.Windows.Forms;

namespace Workshop
{   
    public partial class CustomerLogin : Form
    {
        
        public CustomerLogin()
        {
            InitializeComponent();
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            txtBoxNoMatric.Text = "";
            txtBoxPassword.Text = "";

        }

        private void btnRegister_Click(object sender, EventArgs e)
        {
            CustomerRegister CusReg = new CustomerRegister();
            CusReg.Show();
            this.Hide();
        }

        private void btnBack_Click(object sender, EventArgs e)
        {
            
        }
        public string no_matric;
        
        private void btnLogin_Click(object sender, EventArgs e)
        {
            string no_matric = txtBoxNoMatric.Text;
            string password = txtBoxPassword.Text;

            string queryRegister = $"SELECT * FROM `customers` ";
            //WHERE `no_matric`= '{no_matric}'
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
                            if (no_matric == myReader.GetString(0) && password == myReader.GetString(2))
                            {
                                string uName = myReader.GetString(1);
                               // CustomerSite cSite = new CustomerSite(uName,no_matric);
                                CustSite customerSite = new CustSite(no_matric);
                                
                                // CSProfile cSProfile = new CSProfile(no_matric);
                                //cSite.Show();
                                customerSite.Show();
                                this.Hide();
                                goto x;
                            }
                        }
                    }
                    MessageBox.Show("Wrong combination of Matric No and Password");
                    x:
                    break;
                }

            }
            catch (Exception except)
            {
                MessageBox.Show("Error Occured" + except);
            }
        }

        private void label2_Click(object sender, EventArgs e)
        {
            StartUp stUp = new StartUp();
            stUp.Show();
            this.Hide();

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }
    }
}
