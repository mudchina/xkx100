//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "东厢房");
	set ("long", @LONG
这是知府大人和家眷起居的处所。左首一张雕花大木床，床上堆叠
着锦被和绣花枕头。北边是一条走廊，西边是一个花圃，隐约传来阵阵
花的迷香。
LONG);
	set("exits", ([
		"north" : __DIR__"zoulang",
		"west"  : __DIR__"huapu",
	]));
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("sleep_room", 1); 
	set("coor/x", -1480);
	set("coor/y", -2030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}