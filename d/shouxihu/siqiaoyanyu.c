// Room: /yangzhou/siqiaoyanyu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","四桥烟雨");
	set("long",@LONG
四桥烟雨楼位于瘦西湖东岸，与小金山隔湖相望，旧为盐商黄履暹
别墅，为黄园的南半部分。乾隆南巡时赐名“趣园”。
    四桥烟雨楼面西，二层三楹，四面廊。登楼远眺，虹桥、长春桥、
玉版桥、莲花桥诸桥看似近在咫尺，却桥桥造型各异，风格趣味全然不
同。若在细雨中登楼远眺，诸桥同处雨雾之中，如蒙上一层轻纱，空朦
变幻，空蒙变幻，可得四桥烟雨之意趣。乾隆每次游湖，均要登四桥烟
雨楼凭窗眺望。
LONG );
	set("outdoors", "shouxihu");

	set("exits", ([
		"west"  : __DIR__"chunboqiao",
		"south" : __DIR__"hepuxunfeng",
	]));
	set("objects", ([
		"/d/taishan/npc/shu-sheng" : 1,
	]));
	set("coor/x", 2);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}