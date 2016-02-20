//Edited by fandog, 02/15/2000

inherit ROOM;
void create()
{
	set("short", "药材店");
	set("long", @LONG
这是一家药材店，走进来便闻到刺鼻的药味儿。药柜上几百个小抽
屉分门别类地写着药名和价格。药店掌柜坐在茶几旁，独自喝着茶，看
也不看你一眼。一名小伙计站在柜台后招呼着顾客。柜台上贴着一张发
黄的广告(guanggao)。
LONG );
	set("item_desc", ([
		"guanggao" : "本店出售以下药品：
当归  灵芝  田七  红参  金钗\n"
	]));
	set("objects", ([
		__DIR__"npc/boss1" : 1,
		__DIR__"npc/huoji1" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"hzjie4",
	]));
	set("coor/x", -1510);
	set("coor/y", -2130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}