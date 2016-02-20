// Room: /d/yanping/yanxianshan.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "衍仙山");
	set("long", @LONG
传说晋代延平人衍客结庐于此炼丹成佛。此处峰峦危岩嶙峋，草木
荟蔚，山花烂熳，涧泉爽人，景色奇丽，文人美称其为“衍麓晴霞”，
列为延平八景之一。诗人颂之曰：“仙人何去住，丹炷演山前。天开云
锦烂，疑是紫炉烟。”
　　岩壁上巍然屹立着一尊巧夺天工的天然石佛，高约五丈，头稍俯视。
在其背后的山麓上，还有酷似坐式石佛的块岩。
LONG );
	set("exits", ([
		"northeast" : __DIR__"gubao",
	]));
	set("outdoors", "yanping");
	set("no_clean_up", 0);
	set("coor/x", 1480);
	set("coor/y", -6120);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
