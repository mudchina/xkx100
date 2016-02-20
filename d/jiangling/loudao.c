//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "楼道");
	set ("long", @LONG
你推门入内，拾级上楼，黑暗中听得楼梯发出轻微的吱吱之声，脚
下只觉虚浮浮的，甚不自在。到得楼顶，侧耳静听，绝无半点声息，朦
胧微光中见左首有门。
LONG);
	set("exits", ([ 
		"east" : __DIR__"kongwu1",
		"down" : __DIR__"loudi",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1460);
	set("coor/y", -2039);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
