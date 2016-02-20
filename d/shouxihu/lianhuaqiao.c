// Room: /yangzhou/lianhuaqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","莲花桥");
	set("long",@LONG
莲花桥位于“水云胜概”、“白塔晴云”之间, 因横跨瘦西湖莲花
埂上，故名莲花桥；又因桥上置五亭，故俗称五亭桥。此桥为乾隆巡盐
御史高恒所建，桥基平面分成十二个大小不同的桥墩，主轴线两侧有四
双对称的方形桥墩，构成桥的四个翼角。每个突出的翼角，其三面各有
一个券洞，宽近一丈，小舟可穿游其间；中心券洞阔三丈，可通画舫；
两侧桥堍是少见的半拱形券洞，正侧共十五个券洞，互相通连，月满时，
每洞各衔一月。
    圆的桥洞，方的石块，弧形的桥背，方、圆之间搭配和谐。桥上用
二十八根红柱支撑五亭，中亭高出，为重檐四角攒尖式；翼角四亭，单
檐翘角，角系风铃。亭面皆覆黄色琉璃瓦，檐脊为绿色琉璃瓦，亭内彩
绘藻井，亭间有廊相连，围以石栏，柱头雕各式石狮。宛如一条锦带束
在瘦西湖腰间，又似一朵盛开的莲花浮于水面，
LONG );
	set("outdoors", "shouxihu");

	set("exits", ([
		"north" : __DIR__"shuiyun",
		"south" : __DIR__"pingtai4",
	]));
	set("objects", ([
		"/d/city/npc/lady2" : 2,
	]));
	set("coor/x", -10);
	set("coor/y", 100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
