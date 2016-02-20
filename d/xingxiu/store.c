// room: /d/xingxiu/nanjiang.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "杂货铺");
	set("long", @LONG
这是一个杂货铺。房屋内铺着地毯。店老板坐在地毯上，旁边堆着
他的货。墙上有个牌子，是个价目表(sign)。
LONG
	);
	set("exits", ([ 
	    "east" : __DIR__"yili",
	]));
	set("objects", ([
		__DIR__"npc/maimaiti": 1
	]) );
	set("item_desc", ([ /* sizeof() == 1 */
"sign" : "牌子上写道：

中原钱币通用。

       马奶酒壶(hu)           一百文
       馕(nang)	              五十文
       火折(fire)             一百文
       哈密瓜(gua)            四十文
       冬不拉(dongbula)       一百文
       弯刀(wandao)       一千五百文
       羊皮(yangpi)           三百文
       伊犁马(horse)          一千文 ( 售完 )
\n"
	]));
//	set("no_clean_up", 0);
	set("coor/x", -39100);
	set("coor/y", 13000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

 
