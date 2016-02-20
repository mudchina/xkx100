// Room: /d/yanping/3800kan.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "三千八百坎");
	set("long", @LONG
自古入闽无敞途。往来货运全靠肩挑背扛，逶迤入闽，车马不通。
这段古道号称“三千八百坎”，宽仅三尺，青石砌就，阶如长龙，盘曲
蜿蜒，萦绕碧峰，甚为壮观。行商头脚相继，直达峰顶古堡。相传老农
王堂选筹资多年，亲率工匠用了十年时间勘察设计，凿岩削壁，铺筑石
阶，重修古道，乃成坦途。萨镇冰勒石“义声载道”于中途。故老相传：
“三千八百坎，坎坎有黄金”。
    由此下到坎底衍仙山麓，就是延平府城了。
LONG );
	set("exits", ([
		"northup"   : __DIR__"banyanting",
		"southdown" : __DIR__"yidao3",
	]));
	set("objects", ([
		"/d/taishan/npc/tiao-fu" : 2,
	]));
	set("outdoors", "yanping");
	setup();
	replace_program(ROOM);
}
