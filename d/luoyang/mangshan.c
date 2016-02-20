// Room: /d/luoyang/mangshan.c
// Last modified by winder 2002.11.11

inherit ROOM;

void create()
{
	set("short", "邙山晚眺");
	set("long", @LONG
俗话说“生在苏杭，葬在北邙”，古人把气势雄伟，土质深厚的北
邙当作死后长眠的好地方。孟津新庄村附近古冢林立，这就是东汉诸陵
和王公大臣们的墓葬区。
LONG);
	set("exits", ([  /*  sizeof()  ==  2  */
		"northwest" : __DIR__"shangqing",
		"northeast" : __DIR__"lvzuan",
		"southdown" : __DIR__"road6",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", 50);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
