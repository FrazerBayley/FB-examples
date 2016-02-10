package assignment4;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import java.util.ArrayList;

import javax.swing.JPanel;

public class Paint extends JPanel 
{
	private int _size = 10;  //sets default size of point (small)
	private ArrayList<PaintObject> _points;	//prepares ArrayList
	private Color _color; //prepares _color variable 

	public Paint() 
	{
		setPreferredSize(new Dimension(700, 700)); //sets the size of the GUI 

		_points = new ArrayList<PaintObject>();	//new ArrayList of type PaintObject
		_color = Color.BLACK;	//sets default color
	
		MousePaintAdapter mpa = new MousePaintAdapter(); 
		addMouseMotionListener(mpa);	//listens for mouse drag event
		addMouseListener(mpa);	//listens for mouse click event
	}
	
	class PaintObject //class defines an object (a point) 
	{
		public PaintObject(Point point, Color color, int size) 
		{
			_point = point;
			_color = color;
			_size = size;
		}
		
		final Point _point;
		final Color _color;
		final int _size;
	}
	
	public void setSize(int size) //changes the size 
	{
		_size = size;
		repaint(); //after event occurs it reestablishes all points in ArrayList
	}
	
	public void changeColor(Color color) //changes the color
	{
		_color = color;
		repaint();
	}
	
	public void clearCanvas() //clears the canvas
	{
		_points.clear();
		repaint();
	}

	@Override
	public void paintComponent(Graphics graphics) //places points on canvas 
	{
		super.paintComponent(graphics);
	
		for (PaintObject point: _points)
		{
		graphics.setColor(point._color);
		graphics.fillOval(point._point.x, point._point.y, point._size, point._size);
		}
	}

	private class MousePaintAdapter extends MouseAdapter 
	{
		@Override
	    public void mouseClicked(MouseEvent event) //mouse click listener 
	    {
			_points.add(new PaintObject(event.getPoint(), _color, _size));
			repaint();
	    }
		
		@Override
		public void mouseDragged(MouseEvent event) //mouse drag listener
		{
			_points.add(new PaintObject(event.getPoint(), _color, _size));
			repaint();
		}
	}
	
}
