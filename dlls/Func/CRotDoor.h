/*QUAKED FuncRotDoorSpawn (0 .5 .8) ? START_OPEN REVERSE
DOOR_DONT_LINK TOGGLE X_AXIS Y_AXIS
if two doors touch, they are assumed to be connected and operate as
a unit.

TOGGLE causes the door to wait in both the start and end states for
a trigger event.

START_OPEN causes the door to move to its destination when spawned,
and operate in reverse.  It is used to temporarily or permanently
close off an area when triggered (not usefull for touch or
takedamage doors).

You need to have an origin brush as part of this entity.  The
center of that brush will be
the point around which it is rotated. It will rotate around the Z
axis by default.  You can
check either the X_AXIS or Y_AXIS box to change that.

"distance" is how many degrees the door will be rotated.
"speed" determines how fast the door moves; default value is 100.

REVERSE will cause the door to rotate in the opposite direction.

"angle"		determines the opening direction
"targetname" if set, no touch field will be spawned and a remote
button or trigger field activates the door.
"health"	if set, door must be shot open
"speed"		movement speed (100 default)
"wait"		wait before returning (3 default, -1 = never return)
"dmg"		damage to inflict when blocked (2 default)
"sounds"
0)	no sound
1)	stone
2)	base
3)	stone chain
4)	screechy metal
*/
class CRotDoor : public CBaseDoor
{
public:
	void		Spawn( void );
	int			ObjectCaps() override
	{
		return CBaseDoor::ObjectCaps() | FCAP_INDIRECT_USE;
	}

	virtual void SetToggleState( int state );
};
