package assignment4;


import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;


public class MainFrame extends JFrame 
{
	private Paint _paint; //Paint class object
	
	public MainFrame() 
	{
		super("Paint Program");	//application title
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //quits application when closed
		setLayout(new BorderLayout());	//layout of buttons along border
		
		_paint = new Paint();
		add(_paint, BorderLayout.CENTER);	//sets canvas in the middle of app
		

		JButton redButton = new JButton("Red");	//creates red button
		redButton.addActionListener(new ActionListener() //listens for button click
		{
			@Override
			public void actionPerformed(ActionEvent ev) 
			{
				_paint.changeColor(Color.RED);	//updates the color
			}
		});
		
		JButton greenButton = new JButton("Green"); //creates green button
		greenButton.addActionListener(new ActionListener() 
		{
			@Override
			public void actionPerformed(ActionEvent ev) 
			{
				_paint.changeColor(Color.GREEN);	//updates the color
			}
		});
		
		JButton blackButton = new JButton("Black");	//creates black button
		blackButton.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent ev) 
			{
				_paint.changeColor(Color.BLACK);	//updates the color
			}
		});
		
		JButton blueButton = new JButton("Blue");	//creates blue button
		blueButton.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent ev)
			{
				_paint.changeColor(Color.BLUE);	//updates the color
			}
		});
		
		JButton smallButton = new JButton("Small"); //creates small button
		smallButton.addActionListener(new ActionListener() 
		{
			@Override
			public void actionPerformed(ActionEvent ev)
			{
				_paint.setSize(10);	//updates the size
			}
		});
		
		JButton mediumButton = new JButton("Medium");	//creates medium button
		mediumButton.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent ev) 
			{
				_paint.setSize(20);	//updates size
			}
		});
		
		JButton largeButton = new JButton("Large");	//creates large button
		largeButton.addActionListener(new ActionListener() 
		{
			@Override
			public void actionPerformed(ActionEvent ev) 
			{
				_paint.setSize(30);	//updates button size
			}
		});
		
		JButton clearButton = new JButton("Clear");	//creates clear button
		clearButton.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent ev) 
			{
				_paint.clearCanvas();	//clears the canvas
			}
		});
		
		
		JPanel buttonPanel = new JPanel();
		buttonPanel.setLayout(new GridLayout(4, 1));
		buttonPanel.add(blackButton);
		buttonPanel.add(blueButton);
		buttonPanel.add(greenButton);
		buttonPanel.add(redButton);
		
		add(buttonPanel, BorderLayout.WEST); //sets buttonPanel to left side of app
		
		
		JPanel buttonPanelTwo = new JPanel();
		buttonPanelTwo.setLayout(new GridLayout(4, 1));
		buttonPanelTwo.add(smallButton);
		buttonPanelTwo.add(mediumButton);
		buttonPanelTwo.add(largeButton);
		buttonPanelTwo.add(clearButton);

		add(buttonPanelTwo, BorderLayout.EAST);	//sets buttonPanelTwo to right side of app	
		
		pack();
	}	
}