package httpServer;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.io.IOException;
import java.io.OutputStream;
import java.net.InetSocketAddress;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;

import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.HttpServer;

public class HTTP_Server extends JFrame {
	private JPanel contentPane;
	private JTextField text1;

	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					HTTP_Server frame = new HTTP_Server();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	public HTTP_Server() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);
		HttpServer server;
		try {
			server = HttpServer.create(new InetSocketAddress(8000), 0);
			server.createContext("/test", new MyHandler());
			server.setExecutor(null); // creates a default executor
			server.start();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		text1 = new JTextField();
		text1.setText("STOP");
		contentPane.add(text1, BorderLayout.CENTER);
		text1.setColumns(10);
		setFocusable(true);
		requestFocusInWindow();
		addKeyListener(new KeyAdapter() {
			@Override
			public void keyTyped(KeyEvent e) {
				myKeyEvt(e, true);
			}

			@Override
			public void keyReleased(KeyEvent e) {
				myKeyEvt(e, false);
			}

			@Override
			public void keyPressed(KeyEvent e) {
				myKeyEvt(e, true);
			}

			private void myKeyEvt(KeyEvent e, boolean state) {
				int key = e.getKeyCode();

				if (state == false) {
					text1.setText("STOP");
				} else if (key == KeyEvent.VK_KP_LEFT || key == KeyEvent.VK_LEFT) {
					text1.setText("LEFT");
				} else if (key == KeyEvent.VK_KP_RIGHT || key == KeyEvent.VK_RIGHT) {
					text1.setText("RIGHT");
				} else if (key == KeyEvent.VK_KP_UP || key == KeyEvent.VK_UP) {
					text1.setText("UP");
				} else if (key == KeyEvent.VK_KP_DOWN || key == KeyEvent.VK_DOWN) {
					text1.setText("DOWN");
				}
			}
		});
	}

	class MyHandler implements HttpHandler {
		public void handle(HttpExchange t) throws IOException {
			String response = text1.getText();
			t.sendResponseHeaders(200, response.length());
			OutputStream os = t.getResponseBody();
			os.write(response.getBytes());
			os.close();
		}
	}
}
