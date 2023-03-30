---
layout: default
title: Tags
permalink: /tags/
---

Tags:
<br>
{% assign alltags = "" | split: ',' %}
{%- for post in site.posts -%}
    {%- for tag in post.tags -%}
        {% assign alltags = alltags | push: tag %}
    {%- endfor -%}
{%- endfor -%}
{%- assign alltags = alltags | uniq | sort -%}
{%- for tag in alltags -%}
        <img src="{{site.baseurl}}/tag-solid.svg" height="20"><a href="{{site.baseurl}}/tag/{{tag}}">{{tag}} &nbsp;&nbsp;&nbsp; </a>
{%- endfor -%}
