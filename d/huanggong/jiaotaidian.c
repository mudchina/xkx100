// Room: /d/huanggong/jiaotaidian.c

inherit ROOM;

void create()
{
	set("short", "交泰殿");
	set("long", @LONG
这个亭子形方殿，是皇后过生日庆祝的小礼堂。交泰殿名源于 <周
易> ：“天地交，泰”。殿中放置了象征国家至高权力的二十五颗宝玺。
东侧是一尊铜壶滴漏，西侧是一架大自鸣钟。每年春季，皇后在此举行
喂蚕仪礼。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		 "north" : __DIR__"kunninggong",
		 "south" : __DIR__"qianqinggong",
	]));
	set("objects", ([ /* sizeof() == 4 */
		__DIR__"obj/yuma" : 1,
	]));

	set("coor/x", -200);
	set("coor/y", 5300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}