using System.Runtime.InteropServices;

namespace Viewer
{
    internal static class Program
    {
        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            // To customize application configuration such as set high DPI settings or default font,
            // see https://aka.ms/applicationconfiguration.
            ApplicationConfiguration.Initialize();
            Application.Run(new Form1());
        }
    }

    static class App
    {
        [DllImport("app.dll")]
        public static extern int get_width();
        [DllImport("app.dll")]
        public static extern int get_height();
        [DllImport("app.dll")]
        public static extern unsafe void render(IntPtr frame_data);
    }
}