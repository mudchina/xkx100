//HTQMEN.C

inherit ROOM;

void create()
{
	set("short", "厚土旗门");
	set("long", @LONG
这是厚土旗的洞门，门洞里进进出出的厚土旗众，身上挂满了锹，
铲，短刀，谁也不理你。门边两面短杆镶黄边飞龙旗，绣着厚土二字。
LONG );
	set("exits", ([
		"enter" : __DIR__"htqdating",
		"south" : __DIR__"tohtq7",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52030);
	set("coor/y", 930);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}