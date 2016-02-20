// Room: /yangzhou/baiyipu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","沈家白衣铺");
	set("long",@LONG
店内略有些小，几个人在试看衣服，就显得很拥挤。边上有个裁缝，
正给一小伙子量身材。一个中年男子拿了一套衣服正要去后边更衣室试
衣服。店虽小，可店内陈列的衣服倒不少，各款式的男女成衣应有尽有。
看来你是能在此挑选到自己喜欢的衣服了。店门口挂着个(paizi)。
LONG );
	
	set("item_desc", ([
		"paizi" : "本店招募烫布小工。\n",
	]));	
	set("exits", ([
		"north" : __DIR__"dashixijie",
		"west"  :__DIR__"shenjiakufang",
	]));
	set("objects", ([
		__DIR__"npc/shenwanfu" : 1,
	]));
	set("coor/x", 55);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}