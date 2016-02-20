//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "空屋");
	set ("long", @LONG
一间空荡荡的屋子，连桌椅也没一张。可是瞧那模样，却又不是新
近搬走了家庭用具，而是许多年来一直便如此空无所有。
LONG);
	set("exits", ([ 
		"south" : __DIR__"kongwu1",
	]));
	set("objects", ([ 
		__DIR__"obj/greenflower" : random(2),
	]));
	set("no_clean_up", 0);
	set("coor/x", -1470);
	set("coor/y", -2029);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
