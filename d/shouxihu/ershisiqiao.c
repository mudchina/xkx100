// Room: /yangzhou/ershisiqiao.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","二十四桥");
	set("long",@LONG
二十四桥连接熙春台与望春楼东西两岸，单孔玉带卧波，长十丈，
桥面宽一丈，桥两端踏步各二十四阶，桥两侧围以二十四根玉石栏杆和
二十四块栏板，栏板雕云月纹饰。桥头接水处，以湖石堆叠成巧云状。
桥两端采用错位隐藏手法，使桥身若浮于水面，半圆形桥孔与水中倒影
合成一轮满月。“两堤花柳全依水，一路楼台直到山”。夜来伫立桥上，
可远眺蜀冈，俯视湖面，望月听箫。
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"east" : __DIR__"wangchunlou",
		"west" : __DIR__"pingtai5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -40);
	set("coor/y", 100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}