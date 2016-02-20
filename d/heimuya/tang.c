// Room: /d/heimuya/tang.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;			   
void create()
{
	set("short", "令牌堂");
	set("long",@LONG
这里是黑木崖的第二大堂白虎堂的令牌室。室内青砖铺地。桌上有
一盒子(box1).
LONG );		  
	set("exits", ([	
		"west"  : __DIR__"qing",
	]));
	set("item_desc", ([
		"box1": "这是个放令牌的盒子，不过已被人打开，空空如也 。\n",
       	]) );
	set("no_clean_up", 0);
	set("coor/x", -3030);
	set("coor/y", 3990);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
