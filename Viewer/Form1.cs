using System.Drawing.Imaging;
using System.Runtime.InteropServices;

namespace Viewer
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            Bits = new Int32[App.get_width() * App.get_height()];
            BitsHandle = GCHandle.Alloc(Bits, GCHandleType.Pinned);
            this.frame.Image = new Bitmap(App.get_width(), App.get_height(), sizeof(byte) * 4 * App.get_width(), PixelFormat.Format32bppArgb, BitsHandle.AddrOfPinnedObject());
            this.frame.SizeMode = PictureBoxSizeMode.AutoSize;
            //this.Size = new Size(App.get_width(), App.get_height());
            this.PerformLayout();
        }

        private void refreshTimer_Tick(object sender, EventArgs e)
        {
            App.render(BitsHandle.AddrOfPinnedObject());
            this.Refresh();
        }

        public GCHandle BitsHandle { get; set; }

        public int[] Bits { get; set; }
    }
}