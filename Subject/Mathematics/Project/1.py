import math
from os import remove
from manimlib import *
import numpy as np

SPACE_UNIT_TO_PLANE_UNIT = 0.75

class Start(Scene):
  '''开幕
  '''

  CONFIG = {
    "plane_kwargs" : {
      "x_radius" : FRAME_X_RADIUS/SPACE_UNIT_TO_PLANE_UNIT,
      "y_radius" : FRAME_Y_RADIUS/SPACE_UNIT_TO_PLANE_UNIT,
      "space_unit_to_x_unit" : SPACE_UNIT_TO_PLANE_UNIT,
      "space_unit_to_y_unit" : SPACE_UNIT_TO_PLANE_UNIT,
    },
  }

  def construct(self):
    self.draw_plane()
    self.draw_circle()
    self.move_dot_on_the_circle()

    self.change_to_oval()
    self.move_dot_on_the_oval()
    self.change_to_quadratic_function()

  def draw_plane(self):
    self.axes = NumberPlane(**self.plane_kwargs)
    self.axes.add(self.axes.get_axis_labels())
    self.axes.add_coordinate_labels()

    self.axes.scale(2, about_point=ORIGIN)

    self.play(ShowCreation(self.axes), run_time = 0.5)

  def draw_circle(self):
    circle = Circle(
        radius = self.axes.get_x_unit_size(),
        color = YELLOW,
        arc_center = self.axes.get_origin()
    )

    equation = VGroup(
      Tex("x = \\cos\\theta"),
      Tex("y = \\sin\\theta")
    )
    equation.arrange(DOWN)
    equation.add_background_rectangle()
    equation.next_to(
        circle.point_from_proportion(1./8), 
        UP + RIGHT
    )
    equation.to_edge(RIGHT, buff = 1.5)

    self.equation = VGroup(equation, Brace(equation, LEFT))
    self.play(
      ShowCreation(circle, run_time = 2),
      Write(self.equation),
      run_time = 1.2)
    self.wait(0.3)

    self.circle = circle

  def move_dot_on_the_circle(self):
    dot = SmallDot(color = RED)
    self.theta = ValueTracker(0)
    f_always(
      dot.move_to,
      lambda: self.axes.c2p(math.cos(self.theta.get_value()), math.sin(self.theta.get_value()))
    )
    dn = [DecimalNumber(), DecimalNumber(), DecimalNumber()]
    equation = VGroup(
      VGroup(Tex("x = \\cos"), dn[0]),
      VGroup(Tex("y = \\sin"), dn[1]),
      VGroup(Tex("\\theta = "), dn[2])
    )
    for i in equation:
      i.arrange()
    equation.arrange(DOWN)
    equation.add_background_rectangle()
    equation.next_to(
        self.circle.point_from_proportion(1./8), 
        UP + RIGHT
    )
    equation.to_edge(RIGHT, buff = 1.5)

    self.radial_line = Line(self.axes.get_origin(), dot, color = MAROON_B)
    self.radial_line.add_updater(lambda m: self.radial_line.become(Line(self.axes.get_origin(), dot, color = MAROON_B)))
    self.play(
      ShowCreation(dot),
      FadeIn(self.radial_line),
      self.equation.animate.become(VGroup(equation, Brace(equation, LEFT))))
    
    equation = self.equation[0]
    for i in equation[1:]:
      self.remove(i[1])
    for i in dn:
      f_always(i.set_value, self.theta.get_value)
      self.add(i)

    self.play(self.theta.animate.set_value(2 * np.pi), run_time = 3)

    self.dot = dot
    for i in dn:
      self.remove(i)

  def change_to_oval(self):
    self.dot.clear_updaters()
    equation = VGroup(
      Tex("x = 2\\cos\\theta"),
      Tex("y = \\sin\\theta")
    )
    equation.arrange(DOWN)
    equation.add_background_rectangle()
    equation.next_to(
        self.circle.point_from_proportion(1./8), 
        UP + RIGHT
    )
    equation.to_edge(RIGHT, buff = 1)

    self.play(
      self.equation.animate.become(VGroup(equation, Brace(equation, LEFT))),
      self.circle.animate.apply_matrix([[2, 0],[0, 1]], about_point = self.axes.get_origin()),
      self.dot.animate.move_to(self.axes.c2p(2, 0)),
      run_time = 0.7
    )

    self.wait(0.3)

  def move_dot_on_the_oval(self):
    self.theta.set_value(0)
    f_always(
      self.dot.move_to,
      lambda: self.axes.c2p(2 * math.cos(self.theta.get_value()), math.sin(self.theta.get_value()))
    )
    dn = [DecimalNumber(), DecimalNumber(), DecimalNumber()]
    equation = VGroup(
      VGroup(Tex("x = 2\\cos"), dn[0]),
      VGroup(Tex("y = \\sin"), dn[1]),
      VGroup(Tex("\\theta = "), dn[2])
    )
    for i in equation:
      i.arrange()
    equation.arrange(DOWN)
    equation.add_background_rectangle()
    equation.next_to(
        self.circle.point_from_proportion(1./8), 
        UP + RIGHT
    )
    equation.to_edge(RIGHT, buff = 1)
    self.play(self.equation.animate.become(VGroup(equation, Brace(equation, LEFT))))

    equation = self.equation[0]
    for i in equation[1:]:
      self.remove(i[1])
    for i in dn:
      f_always(i.set_value, self.theta.get_value)
      self.add(i)

    self.play(self.theta.animate.set_value(2 * np.pi), run_time = 3)
    for i in dn:
      self.remove(i)

  def change_to_quadratic_function(self):
    self.dot.clear_updaters()
    equation = VGroup(
      Tex("x = 6", "t"),
      Tex("y = 5", "t^2")
    )
    equation.arrange(DOWN)
    equation.add_background_rectangle()
    equation.next_to(
        self.circle.point_from_proportion(1./8), 
        UP + RIGHT
    )
    equation.to_edge(RIGHT, buff = 0.5)
    self.brace = Brace(equation, LEFT)
    self.play(
      self.equation.animate.become(equation),
      self.axes.animate.scale(0.5, about_point = ORIGIN),
      self.circle.animate.scale(0.5, about_point = self.axes.get_origin()),
      ShowCreation(self.brace),
      run_time = 1
    )

    self.play(
      self.circle.animate.become(self.axes.get_graph(lambda x: (5/36) * x * x )),
      self.dot.animate.move_to(self.axes.c2p(0, 0)),
      run_time = 0.5
    )

    self.wait(0.5)