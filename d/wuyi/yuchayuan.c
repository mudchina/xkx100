// Room: /d/wuyi/yuchayuan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "御茶园");
	set("long", @LONG
御茶园位于四曲南边的一块平地上。元初，一个叫高兴的官吏为了
媚上，向皇帝献了几斤武夷“石乳”。从此，年年二十斤的“石乳”就
成了历任崇安县令的政绩。为防以次充好，高兴最后还是上奏皇帝，在
此建起了盛极一时的御茶园。每年“惊蛰”那一天，喊山台上阵阵“茶
发芽了，茶发芽了！”的呼叫声，时时扣击着岁月的期盼。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"tongxianjing",
		"north" : __DIR__"5qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1380);
	set("coor/y", -5020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

