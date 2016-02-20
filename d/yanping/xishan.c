// Room: /d/yanping/xishan.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "西山");
	set("long", @LONG
西山屹立在府城中央，山顶就是州学。半山处，是一碑亭，亭联
“独先天下兴州学，屹立西山励后贤”。亭内是“南剑州重建州学记
碑” (bei)，碑文记述此地山川形胜，文章风流之盛事，追昔抚今，
感慨无限。
LONG );
	set("exits", ([
		"northup"   : __DIR__"zhouxue",
		"southdown" : __DIR__"road3",
	]));
	set("item_desc", ([
		"bei" :
"
碑由黑页岩雕成，圆首，篆额，高丈许，阔六尺，花岗岩龟趺座，
进士张致远撰文，进士罗荐可书。

                    南剑州重建州学记

    延平郡治，当七闽之冲。而旧学跨西山，特踞形胜。九龙、双
旌、演仙、文笔诸峰皆秀拔摩云，环顾如列屏障。建、剑二水会而
南流。风雨晦暝，神物吼越，潭静天开，想紫光隐隐牛斗间。异时
伟人辈出，其冠巍科，跻怃仕，术业足以师世，循良忠烈足以动宸
极，而厌绅芴者相望也。......
"
	]));
	set("outdoors", "yanping");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
