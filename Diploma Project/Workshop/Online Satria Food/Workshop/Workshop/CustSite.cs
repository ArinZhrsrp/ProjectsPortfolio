using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Drawing;
using System.IO;
using System.Windows.Forms;


namespace Workshop
{
    public partial class CustSite : Form
    {
        double total;
        string no_Matric;

        PictureBox pic = new PictureBox();

        public CustSite()
        {
            InitializeComponent();
        }

        private void metroTabPage1_Click(object sender, EventArgs e)
        {

        }
        public CustSite(string noMatric)
        {
            InitializeComponent();
            profile(noMatric);

        }

        public void profile(string no_matric)
        {

            this.no_Matric = no_matric;
            string queryRegister = $"SELECT * FROM `customers` WHERE `no_matric` = '{no_matric}'";
            string mySqlConnection = "datasource=127.0.0.1;port=3306;username=root;password=;database=online_satria_food";
            MySqlConnection databaseConnection = new MySqlConnection(mySqlConnection);
            MySqlCommand commandDatabase = new MySqlCommand(queryRegister, databaseConnection);


            try
            {
                databaseConnection.Open();
                MySqlDataReader myReader = commandDatabase.ExecuteReader();

                if (myReader.HasRows)
                {
                    while (myReader.Read())
                    {
                        txtUName.Text = myReader.GetString(1);
                        txtPass.Text = myReader.GetString(2);
                        txtHP.Text = myReader.GetString(3);
                    }
                }
                databaseConnection.Close();

            }
            catch (Exception except)
            {
                MessageBox.Show("Error Occured" + except);
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            txtUName.ReadOnly = false;
            txtPass.ReadOnly = false;
            txtHP.ReadOnly = false;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string userName = txtUName.Text;
            string pass = txtPass.Text;
            string phoneNo = txtHP.Text;
            string queryRegister = $"UPDATE `customers` SET `c_name`='{userName}',`c_password`='{pass}',`c_phone_no`='{phoneNo}' WHERE `no_matric`='{no_Matric}'";
            string mySqlConnection = "datasource=127.0.0.1;port=3306;username=root;password=;database=online_satria_food";
            MySqlConnection databaseConnection = new MySqlConnection(mySqlConnection);
            MySqlCommand commandDatabase = new MySqlCommand(queryRegister, databaseConnection);


            try
            {
                databaseConnection.Open();
                MySqlDataReader myReader = commandDatabase.ExecuteReader();
                MessageBox.Show("Profile Updated!");
                databaseConnection.Close();
                txtUName.ReadOnly = true;
                txtPass.ReadOnly = true;
                txtHP.ReadOnly = true;
                databaseConnection.Close();

            }
            catch (Exception except)
            {
                MessageBox.Show("Error Occured" + except);
            }
        }

        private void label4_Click(object sender, EventArgs e)
        {
            this.Dispose();
            CustomerLogin cLogin = new CustomerLogin();
            cLogin.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            //food_UC1.BringToFront();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            //   drinks_UC1.BringToFront();
        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {
            order();


        }

        private void flowLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }
        private void order()
        {
            flowLayoutPanel1.Controls.Clear();
            string mySqlConnection = "datasource=127.0.0.1;port=3306;username=root;password=;database=online_satria_food";
            string query = "SELECT * FROM `product` WHERE `Name` LIKE '%" + txtsearch.Text + "%'ORDER BY `Name`";
            MySqlConnection databaseConnection = new MySqlConnection(mySqlConnection);
            MySqlCommand cmd = new MySqlCommand(query, databaseConnection);

            try
            {
                while (flowLayoutPanel1.Controls.Count > 0)
                {
                    flowLayoutPanel1.Controls[0].Dispose();
                }

                databaseConnection.Open();

                MySqlDataAdapter dA = new MySqlDataAdapter(cmd);
                DataTable table = new DataTable();
                dA.Fill(table);


                for (int n = 0; n < table.Rows.Count; n++)
                {
                    byte[] img = ((byte[])table.Rows[n]["Image"]);

                    MemoryStream stream = new MemoryStream(img);


                    PictureBox pic1 = new PictureBox();
                    Panel panelbox = new Panel();
                    Label mylab = new Label();
                    Label mylab2 = new Label();


                    mylab2.Text = "RM " + table.Rows[n]["Price"].ToString();
                    mylab2.Location = new Point(2, 170);
                    mylab2.AutoSize = true;
                    mylab2.Font = new Font("Calibri", 10);
                    mylab2.ForeColor = Color.Red;
                    mylab2.Padding = new Padding(2);

                    mylab.Text = table.Rows[n]["Name"].ToString();
                    mylab.Location = new Point(1, 150);
                    mylab.AutoSize = true;
                    mylab.Font = new Font("Calibri", 10);
                    mylab.ForeColor = Color.Green;
                    mylab.Padding = new Padding(2);

                    panelbox.Size = new Size(190, 229);

                    pic1.Width = 300;
                    pic1.Height = 300;
                    pic1.BackgroundImageLayout = ImageLayout.Stretch;
                    pic1.BorderStyle = BorderStyle.None;

                    pic1.Size = new System.Drawing.Size(133, 145);
                    pic1.BorderStyle = BorderStyle.None;
                    pic1.Image = Image.FromStream(stream);
                    pic1.SizeMode = PictureBoxSizeMode.StretchImage;
                    pic1.Tag = table.Rows[n]["ID"].ToString();

                    this.flowLayoutPanel1.AutoScroll = true;
                    panelbox.Controls.Add(pic1);
                    panelbox.Controls.Add(mylab2);
                    panelbox.Controls.Add(mylab);
                    this.flowLayoutPanel1.Controls.Add(panelbox);

                    pic1.Click += new EventHandler(onclick);
                    dA.Dispose();


                }


                databaseConnection.Close();

            }
            catch (Exception ex)
            {
                MessageBox.Show("Something is wrong ! " + ex);
            }
        }
        public void onclick(object sender, EventArgs e)
        {
            string tag = ((PictureBox)sender).Tag.ToString();
            string mySqlConnection = "datasource=127.0.0.1;port=3306;username=root;password=;database=online_satria_food";
            string query = "SELECT * FROM `product` WHERE `ID` LIKE '" + tag + "'";
            MySqlConnection databaseConnection = new MySqlConnection(mySqlConnection);
            MySqlCommand cmd = new MySqlCommand(query, databaseConnection);
            databaseConnection.Open();
            MySqlDataReader read = cmd.ExecuteReader();
            read.Read();
            if (read.HasRows)
            {
                total += double.Parse(read["Price"].ToString());

                dataGridView1.Rows.Add(dataGridView1.Rows.Count + 1, read["ID"].ToString(), read["Name"].ToString(), "RM " + double.Parse(read["Price"].ToString()).ToString("#,##0.00"));
            }
            read.Close();
            databaseConnection.Close();
            lbltotal.Text = total.ToString("#,##0.00");

        }


        private void txtsearch_TextChanged_1(object sender, EventArgs e)
        {
            order();
        }

        private void button3_Click_1(object sender, EventArgs e)
        {
            dataGridView1.Rows.Clear();
            lbltotal.Text = "0.00";
        }

        private void button4_Click_1(object sender, EventArgs e)
        {
            int id;
            DateTime date = DateTime.Now; // will give the date for today
            string date2 = date.ToLongDateString();

            for (int i = 0; i < dataGridView1.Rows.Count; i++)
            {

                id = Int32.Parse(dataGridView1.Rows[i].Cells[1].Value.ToString());
                string queryRegister = $"INSERT INTO `history`(`no_matric`, `p_id`, `Date`) VALUES ('{no_Matric}','{id}','{date2}')";
                string mySqlConnection = "datasource=127.0.0.1;port=3306;username=root;password=;database=online_satria_food";
                MySqlConnection databaseConnection = new MySqlConnection(mySqlConnection);
                MySqlCommand commandDatabase = new MySqlCommand(queryRegister, databaseConnection);

                try
                {
                    databaseConnection.Open();


                    MySqlDataReader myReader = commandDatabase.ExecuteReader();
                    
                    databaseConnection.Close();

                }
                catch (Exception except)
                {
                    MessageBox.Show("Error Occured" + except);
                }

            }
            MessageBox.Show("Order Succesfull!");
        }

        private void metroTabPage3_Click(object sender, EventArgs e)
        {

        }

        private void button5_Click(object sender, EventArgs e)
        {
            string mySqlConnection = "datasource=127.0.0.1;port=3306;username=root;password=;database=online_satria_food";

            string query = $"SELECT customers.c_name AS 'Customer Name',product.Name,product.Price,history.Date,history.status " +
                $"FROM customers JOIN history JOIN product WHERE customers.no_matric='{no_Matric}' " +
                $"AND history.no_matric = customers.no_matric AND product.ID = history.p_id";

            MySqlConnection databaseConnection = new MySqlConnection(mySqlConnection);
            MySqlDataAdapter dataAdapt = new MySqlDataAdapter(query, databaseConnection);

            try
            {
                databaseConnection.Open();
                DataSet datSet = new DataSet();
                dataAdapt.Fill(datSet, "history");
                dataGridView2.DataSource = datSet.Tables["history"];
                databaseConnection.Close();

            }
            catch (Exception except)
            {
                MessageBox.Show("Error occured" + except.Message);
            }
        }

        private void lbltotal_Click(object sender, EventArgs e)
        {

        }
    }
}
