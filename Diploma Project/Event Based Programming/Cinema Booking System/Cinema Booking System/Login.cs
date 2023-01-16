using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Cinema_Booking_System
{
    public partial class Login : Form
    {
        Person person = new Person();

        public Login()
        {
            InitializeComponent();
        }

        SqlConnection sqlcon = new SqlConnection(@"Data Source = (LocalDB)\MSSQLLocalDB; AttachDbFilename=C:\Users\Arin\Desktop\Sem Lepas\Mini Project\Cinema Booking System\CinemaBookingSystem.mdf;Integrated Security = True");

        private void buttonLogin_Click(object sender, EventArgs e)
        {
            SqlDataAdapter sda = new SqlDataAdapter("select userName [Name], roleName [Role] from userTable inner join userRoleTable on userRoleTable.userId = userTable.userId inner join roleTable on roleTable.roleId = userRoleTable.roleId where userUsername = '"+textBoxUsername.Text+"' and userPassword = '"+textBoxPass.Text+"'", sqlcon);
            DataTable dt = new DataTable();
            sda.Fill(dt);

            if(dt.Rows.Count != 0)
            {
                foreach(DataRow dr in dt.Rows)
                {
                    person.Name = dr["Name"].ToString();
                    person.Role = dr["Role"].ToString();
                }

                Main main = new Main(person.Role);
                main.Show();
                this.Hide();
            }
            else
            {
                labelError.Visible = true;
            }
        }

        private void Login_Click(object sender, EventArgs e)
        {
            labelError.Visible = false;
        }

        private void textBoxPass_KeyPress(object sender, KeyPressEventArgs e)
        {
            if(e.KeyChar == (char)Keys.Enter)
            {
                e.Handled = true;
                SqlDataAdapter sda = new SqlDataAdapter("select userName [Name], roleName [Role] from userTable inner join userRoleTable on userRoleTable.userId = userTable.userId inner join roleTable on roleTable.roleId = userRoleTable.roleId where userUsername = '" + textBoxUsername.Text + "' and userPassword = '" + textBoxPass.Text + "'", sqlcon);
                DataTable dt = new DataTable();
                sda.Fill(dt);

                if (dt.Rows.Count != 0)
                {
                    foreach (DataRow dr in dt.Rows)
                    {
                        person.Name = dr["Name"].ToString();
                        person.Role = dr["Role"].ToString();
                    }

                    Main main = new Main(person.Role);
                    main.Show();
                    this.Hide();
                }
                else
                {
                    labelError.Visible = true;
                }
            }
        }
    }
}
