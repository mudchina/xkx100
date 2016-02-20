// Room: /yangzhou/woshi.c
// Last Modified by Winder on Jul. 20 2000

#include <room.h>
inherit ROOM;

void create()
{
	set("short","卧室");
	set("long",@LONG
沿窗列一紫檀妆台，上用绣花红呢罩。一榻床，榻前悬一立轴，系
绘《文君私奔图》。左右楹联(lian)笔法甚秀。珠帘隐隐，香雾沉沉，
其最雅者朝外排一床，周围皆书画，纱窗内悬异式珠灯，外悬湖色床幔，
左右垂银丝钩。幔之内悬一小额曰“温柔乡”，流苏帐，鸳鸯被，合欢
枕，俱异香可爱。
LONG    
	);
	set("exits",([ /* sizeof() == 3 */
		"west" : __DIR__"waifang",
	]));
	set("item_desc" , ([
		"lian" :"	仙       丽\n"
			"	才       句\n" 
			"	俊       妙\n" 
			"	似       于\n" 
			"	东       天\n" 
			"	海       下\n"
			"	青       白\n",
	]));
	create_door("west", "纱橱门", "east" , DOOR_CLOSED); 
	set("coor/x", 60);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
}