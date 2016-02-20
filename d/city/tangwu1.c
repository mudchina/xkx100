// Room: /yangzhou/tangwu1.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "堂屋");
	set("long", @LONG
屋之南北饰一雕花窗栏隔扇，东西两山墙辟有大块窗格，四面空明。
正中壁上笔悬一幅巨制梅桩中堂，笔力遒劲，墨气飞动，左右挂一楹联
(lian)。倚墙设一套红木条几，上陈古瓶，盆景。几前一海梅雕花方桌，
桌旁一对海梅雕花太师椅。设竹榻，榻旁一架古书，缥湘零乱。
LONG );

	set("item_desc", ([
		"lian" : @LONG
                  ┌─┐          ┌─┐ 
                  │倚│          │登│
                  │栏│          │楼│
                  │潜│          │清│
                  │窥│          │听│
                  │鸟│          │市│
                  │梦│          │声│
                  │闲│          │远│
                  └─┘          └─┘
LONG,
	]));
	set("exits", ([
		"south" : __DIR__"rongxiyuan",
	]));
	set("objects", ([
		__DIR__"npc/qiuhaoshi" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", -39);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}