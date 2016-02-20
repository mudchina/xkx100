// ROOM : biguan.c
inherit ROOM;
void create()
{
	set("short","闭关室");
	set("long",@LONG
这是天山童姥闭关修练的地方，只见一个身材娇小, 貌如处子的十
八九岁的女子盘膝而坐，她就是闻名天下的天山童姥。如果不是她的亲
传弟子，千万不要轻易打搅。
LONG );
	set("sleep_room", 1);
	set("exits",([
		"south" : __DIR__"men3",
	]));
	set("objects",([
		CLASS_D("lingjiu")+"/tonglao" : 1,
	]));
	set("coor/x", -51000);
	set("coor/y", 30190);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}