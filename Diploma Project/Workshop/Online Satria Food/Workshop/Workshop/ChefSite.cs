using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;

namespace Workshop
{

    public partial class ChefSite : Form
    {
        string p_id;
        string NoMatric;
        string chefID;
        public ChefSite()
        {
            InitializeComponent();
        }
        public ChefSite(string id)
        {
            this.chefID = id;
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string mySqlConnection = "datasource=127.0.0.1;port=3306;username=root;password=;database=online_satria_food";
            string query = $"SELECT customers.c_name AS 'Customer Name',product.Name,product.Price,history.Date,history.status,history.p_id AS 'Product ID',history.no_matric AS 'No Matric' FROM customers JOIN history JOIN product WHERE customers.no_matric=history.no_matric AND history.p_id=product.ID AND status=''";
            MySqlConnection databaseConnection = new MySqlConnection(mySqlConnection);
            MySqlDataAdapter dataAdapt = new MySqlDataAdapter(query, databaseConnection);

            try
            {
                databaseConnection.Open();
                DataSet datSet = new DataSet();
                dataAdapt.Fill(datSet, "history");
                dataGridView1.DataSource = datSet.Tables["history"];
                databaseConnection.Close();

            }
            catch (Exception except)
            {
                MessageBox.Show("Error occured" + except.Message);
            }
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex >= 0)
            {
                dataGridView1.CurrentRow.Selected = true;
                string p_id2;
                string NoMatric2;
                string status;
                p_id2 = dataGridView1.Rows[e.RowIndex].Cells["Product ID"].FormattedValue.ToString();
                NoMatric2 = dataGridView1.Rows[e.RowIndex].Cells["No Matric"].FormattedValue.ToString();
                status = dataGridView1.Rows[e.RowIndex].Cells["status"].FormattedValue.ToString();
                label1.Text = NoMatric2;
                label2.Text = p_id2;
                comboBox1.SelectedItem = status;
                this.p_id = p_id2;
                this.NoMatric = NoMatric2;

            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            string status2 = comboBox1.SelectedItem.ToString();
            string mySqlConnection = "datasource=127.0.0.1;port=3306;username=root;password=;database=online_satria_food";
            string query = $"UPDATE `history` SET `status`='{status2}',`chef_id`='{chefID}' WHERE `no_matric`='{NoMatric}' AND `p_id`='{p_id}'";
            MySqlConnection databaseConnection = new MySqlConnection(mySqlConnection);
            MySqlCommand commandDatabase = new MySqlCommand(query, databaseConnection);

            try
            {
                databaseConnection.Open();
                MySqlDataReader myReader = commandDatabase.ExecuteReader();
                MessageBox.Show("Order Status updated!");
                databaseConnection.Close();

            }
            catch (Exception except)
            {
                MessageBox.Show("Error occured" + except.Message);
            }

        }

        private void label7_Click(object sender, EventArgs e)
        {
            ChefLogin clogin = new ChefLogin();
            clogin.Show();
            this.Hide();
        }

        private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            string theDate = dateTimePicker1.Value.ToString("dddd, MMMM d, yyyy");
            label10.Text = theDate;

            string mySqlConnection = "datasource=127.0.0.1;port=3306;username=root;password=;database=online_satria_food";
            string query = $"SELECT  COUNT(product.ID) AS 'Quantity',product.Name,SUM(product.Price) AS 'Price', history.Date FROM history JOIN product WHERE status='Completed' AND history.p_id = product.ID AND history.Date ='{theDate}' GROUP BY product.ID";
            //string query = $"SELECT  COUNT(product.ID) AS 'Quantity',product.Name,SUM(product.Price) AS 'Price', history.Date FROM history JOIN product WHERE status='Completed' AND history.p_id = product.ID GROUP BY product.ID";
            MySqlConnection databaseConnection = new MySqlConnection(mySqlConnection);
            MySqlDataAdapter dataAdapt = new MySqlDataAdapter(query, databaseConnection);

            try
            {
                databaseConnection.Open();
                DataSet datSet = new DataSet();
                dataAdapt.Fill(datSet, "history");
                dataGridView2.DataSource = datSet.Tables["history"];

                int sum = 0;
                int total = 0;
                for (int i = 0; i < dataGridView2.Rows.Count; ++i)
                {
                    sum += Convert.ToInt32(dataGridView2.Rows[i].Cells[2].Value);
                    total += Convert.ToInt32(dataGridView2.Rows[i].Cells[0].Value);
                }
                lblTotal.Text = "RM" + sum.ToString();
                lblTotalProduct.Text = total.ToString();
                
                int balance = Int32.Parse(textBox1.Text) - sum;
                if (sum < Int32.Parse(textBox1.Text))
                {
                    label14.ForeColor = System.Drawing.Color.Red;
                    label14.Text = ("RM" + balance.ToString());
                }
                else 
                {
                    label14.ForeColor = System.Drawing.Color.Green;
                    label14.Text = ("RM" + balance.ToString());
                }
                databaseConnection.Close();

            }
            catch (Exception except)
            {
                MessageBox.Show("Error occured" + except.Message);
            }

        }

        private void label14_Click(object sender, EventArgs e)
        {

        }
    }
}
