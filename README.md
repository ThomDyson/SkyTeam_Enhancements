# SkyTeam Physical Control Enhancements
Sky Team is a two-player cooperative table-top game where the players try to land a plane.
Mansol posted a great 3d printed design on Printables to convert Sky Team to use phyical switches. https://www.printables.com/model/1144707-sky-team-3d-printable-upgrade

I've reworked the wiring and the code for the pilot. This code enforces the required switch sequence for brake controls. If you turn on the brakes out of order, the switch indicator light will flash. If you turn them on in the correct order, the lights will be steady and the braking speed indicators will light in order. Gear controls do not have a required order; they can be turned on in any order.

The image from TinkerCad shows an Arduino UNO, but this works with, and is meant for, a Nano. The complete set requries 3 devices, so you have to use Nanos to make them fit in the case.

Co-pilot controls are coming soon.
