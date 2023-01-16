using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.IO;
using System.Drawing;

namespace Workshop
{
    public partial class AdminSite : Form
    {
        //string Image = "";
        public AdminSite()
        {
            InitializeComponent();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {


        }

        private void btnrefresh_Click(object sender, EventArgs e)
        {
            string queryRefresh = "SELECT `no_matric`AS 'No Matric', `c_name` AS 'Cust Name', `c_password` AS 'Password', `c_phone_no` AS 'Phone' FROM online_satria_food.customers";

            string mySqlConnection = "datasource=127.0.0.1;port=3306;username=root;password=;database=online_satria_food";

            MySqlConnection databaseConnection = new MySqlConnection(mySqlConnection);

            MySqlDataAdapter dataAdapt = new MySqlDataAdapter(queryRefresh, databaseConnection);

            

            try
            {
                databaseConnection.Open();
                DataSet datSet = new DataSet();
                dataAdapt.Fill(datSet, "customers");
                dataGridView1.DataSource = datSet.Tables["customers"];
                databaseConnection.Close();

            }
            catch (Exception except)
            {
                MessageBox.Show("Error occured" + except.Message);
            }
        }

        private void btnDel_Click(object sender, EventArgs e)
        {
            string querySearch = $"SELECT * FROM `customers`";
            string no_matric = txtNoMatric.Text;
            string mySqlConnection2 = "datasource=127.0.0.1;port=3306;username=root;password=;database=online_satria_food";
            MySqlConnection databaseConnection2 = new MySqlConnection(mySqlConnection2);
            MySqlCommand commandDatabase2 = new MySqlCommand(querySearch, databaseConnection2);


            try
            {
                databaseConnection2.Open();
                MySqlDataReader myReader2 = commandDatabase2.ExecuteReader();

                while (true)
                {
                    if (myReader2.HasRows)
                    {
                        while (myReader2.Read())
                        {
                            if (no_matric == myReader2.GetString(0))
                            {

                                string queryDel = $"DELETE FROM `customers` WHERE `no_matric` = '{no_matric}'";
                                string mySqlConnection = "datasource=127.0.0.1;port=3306;username=root;password=;database=online_satria_food";
                                MySqlConnection databaseConnection = new MySqlConnection(mySqlConnection);
                                databaseConnection.Open();
                                MySqlCommand commandDatabase = new MySqlCommand(queryDel, databaseConnection);
                                MySqlDataReader myReader = commandDatabase.ExecuteReader();
                                MessageBox.Show("Account Deleted");
                                databaseConnection.Close();
                                goto x;
                                
                            }

                        }
                    }
                    MessageBox.Show("Account not found");
                    x:
                    break;
                }

                databaseConnection2.Close();

            }
            catch (Exception except)
            {
                MessageBox.Show("Error occured " + except.Message);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string queryRefresh = "SELECT `chef_ID` AS 'Chef ID', `Name` AS 'Name', `Phone` AS 'Phone' FROM online_satria_food.chef";

            string mySqlConnection = "datasource=127.0.0.1;port=3306;username=root;password=;database=online_satria_food";

            MySqlConnection databaseConnection = new MySqlConnection(mySqlConnection);

            MySqlDataAdapter dataAdapt = new MySqlDataAdapter(queryRefresh, databaseConnection);



            try
            {
                databaseConnection.Open();
                DataSet datSet = new DataSet();
                dataAdapt.Fill(datSet, "chef");
                dataGridView2.DataSource = datSet.Tables["chef"];
                databaseConnection.Close();

            }
            catch (Exception except)
            {
                MessageBox.Show("Error occured" + except.Message);
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            string querySearch = $"SELECT * FROM `chef`";
            string id = txtChefID.Text;
            string mySqlConnection2 = "datasource=127.0.0.1;port=3306;username=root;password=;database=online_satria_food";
            MySqlConnection databaseConnection2 = new MySqlConnection(mySqlConnection2);
            MySqlCommand commandDatabase2 = new MySqlCommand(querySearch, databaseConnection2);


            try
            {
                databaseConnection2.Open();
                MySqlDataReader myReader2 = commandDatabase2.ExecuteReader();

                while (true)
                {
                    if (myReader2.HasRows)
                    {
                        while (myReader2.Read())
                        {
                            if (id == myReader2.GetString(0))
                            {

                                string queryDel = $"DELETE FROM `chef` WHERE `chef_id` = '{id}'";
                                string mySqlConnection = "datasource=127.0.0.1;port=3306;username=root;password=;database=online_satria_food";
                                MySqlConnection databaseConnection = new MySqlConnection(mySqlConnection);
                                databaseConnection.Open();
                                MySqlCommand commandDatabase = new MySqlCommand(queryDel, databaseConnection);
                                MySqlDataReader myReader = commandDatabase.ExecuteReader();
                                MessageBox.Show("Account Deleted");
                                databaseConnection.Close();
                                goto x;

                            }

                        }
                    }
                    MessageBox.Show("Account not found");
                x:
                    break;
                }

                databaseConnection2.Close();

            }
            catch (Exception except)
            {
                MessageBox.Show("Error occured " + except.Message);
            }
        }

        private void label3_Click(object sender, EventArgs e)
        {
            StartUp stUp = new StartUp();
            stUp.Show();
            this.Hide();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void lblCustID_Click(object sender, EventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void panel3_Paint(object sender, PaintEventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "Choose Image(*.png) |*.png|jpg files(*.jpg)|*.jpg|All files(*.*)|*.*";

            if (ofd.ShowDialog() == DialogResult.OK) 
            {
                //imgloc = ofd.FileName.ToString();
                pictureBox1.Image = Image.FromFile(ofd.FileName);
            }
        }

        private void button2_Click_1(object sender, EventArgs e)
        {


            try
            {
                MemoryStream ms = new MemoryStream();
                pictureBox1.Image.Save(ms, pictureBox1.Image.RawFormat);
                byte[] img = ms.ToArray();
                MySqlCommand cmd;
                String qry = $"INSERT INTO `product`(`ID`, `Name`, `Price`, `Type`, `Image`, `catID`) VALUES (@ID,@Name,@Price,@Type,@Img,@category)";
                string mySqlConnection = "datasource=127.0.0.1;port=3306;username=root;password=;database=online_satria_food";
                MySqlConnection databaseConnection = new MySqlConnection(mySqlConnection);
                databaseConnection.Open();
                cmd = new MySqlCommand(qry, databaseConnection);
                cmd.Parameters.Add("@Id", MySqlDbType.Int32);
                cmd.Parameters.Add("@Name", MySqlDbType.Text);
                cmd.Parameters.Add("@Price", MySqlDbType.Int32);
                cmd.Parameters.Add("@Type", MySqlDbType.Text);
                cmd.Parameters.Add("@Img", MySqlDbType.Blob);
                cmd.Parameters.Add("@category", MySqlDbType.Text);
                cmd.Parameters["@Id"].Value = textID.Text;
                cmd.Parameters["@Name"].Value = textName.Text;
                cmd.Parameters["@Price"].Value = textPrice.Text;
                cmd.Parameters["@Type"].Value = comboBox1.SelectedItem.ToString();
                cmd.Parameters["@Img"].Value = img;
                cmd.Parameters["@category"].Value = Int32.Parse(comboBox2.SelectedItem.ToString());
                if (cmd.ExecuteNonQuery() == 1)
                {
                    MessageBox.Show("Product Added");
                    textID.Text = "";
                    textPrice.Text = "";
                    textName.Text = "";
                    comboBox1.Text = "";
                    comboBox2.Text = "";
                    pictureBox1.Image = null;
                }
                databaseConnection.Close();
            }
            catch (NullReferenceException) 
            {
                MessageBox.Show("Fill in all the blanks ");
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occcured " + ex);
                //throw;
            }
            

        }

        private void button4_Click(object sender, EventArgs e)
        {
            textID.Text = "";
            textPrice.Text = "";
            textName.Text = "";
            comboBox1.Text = "";
            pictureBox1.Image = null;
            comboBox2.Text = "";

        }

        private void button6_Click(object sender, EventArgs e)
        {
            txtAdID.Text = "";
            txtAdUseName.Text = "";
            txtAdPass.Text = "";
            txtAdPhone.Text = "";
        }

        private void button5_Click(object sender, EventArgs e)
        {
            string adid = txtAdID.Text;
            string Name = txtAdUseName.Text;
            string password = txtAdPass.Text;
            string hp_no = txtAdPhone.Text;
            int adID = Int32.Parse(adid);

            string queryRegister = $"INSERT INTO `admin`(`ID`, `username`, `password`, `phoneNo`) VALUES ('{adID}','{Name}','{password}','{hp_no}')";

            string mySqlConnection = "datasource=127.0.0.1;port=3306;username=root;password=;database=online_satria_food";

            MySqlConnection databaseConnection = new MySqlConnection(mySqlConnection);

            MySqlCommand commandDatabase = new MySqlCommand(queryRegister, databaseConnection);

            try
            {
                databaseConnection.Open();
                MySqlDataReader myReader = commandDatabase.ExecuteReader();
                MessageBox.Show("Successfully Register New Admin");
                txtAdID.Text = "";
                txtAdUseName.Text = "";
                txtAdPass.Text = "";
                txtAdPhone.Text = "";
            }
            catch (Exception except)
            {
                MessageBox.Show("Error While Registering New Admin or Already Register This Account" + except.Message);
            }
        }
    }
}
