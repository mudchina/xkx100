// Room: /d/nanshaolin/xianglu.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "香炉");
	set("long",@LONG
走过石板路就到了寺内最大的香炉旁，此香炉由青铜铸就，有两人
多高炉鼎上精工镂刻了多种瑞兽及代表祥和超脱的佛家典故。炉内青烟
袅袅，端的是佛家无上之宝。炉前香案前，几位香客正自顶礼膜拜。
LONG );
	set("outdoors", "nanshaolin");
	set("exits", ([
		"north" : __DIR__"stoneroad2",
		"south" : __DIR__"sblu-1",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/yuanbei" : 1,
		__DIR__"npc/xiang-ke" : 2,
	]));
	set("coor/x", 1820);
	set("coor/y", -6250);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

