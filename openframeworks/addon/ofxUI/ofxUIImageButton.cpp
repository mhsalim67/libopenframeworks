/********************************************************************************** 
 
 Copyright (C) 2012 Syed Reza Ali (www.syedrezaali.com)
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of
 this software and associated documentation files (the "Software"), to deal in
 the Software without restriction, including without limitation the rights to
 use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 of the Software, and to permit persons to whom the Software is furnished to do
 so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 
 **********************************************************************************/

#include "ofxUIImageButton.h"

ofxUIImageButton::ofxUIImageButton(float x, float y, float w, float h,
                                   bool _value, string _pathURL, string _name)
{
    rect = new ofxUIRectangle(x,y,w,h);
    init(w, h, _value, _pathURL, _name);         
}

ofxUIImageButton::ofxUIImageButton(float w, float h, bool _value,
                                   string _pathURL, string _name)
{
    rect = new ofxUIRectangle(0,0,w,h);
    init(w, h, _value, _pathURL, _name);         
}

ofxUIImageButton::~ofxUIImageButton()
{
    delete img; 
}


void ofxUIImageButton::init(float w, float h, bool _value, string _pathURL,
                            string _name)
{
    name = _name; 		
    kind = OFX_UI_WIDGET_IMAGEBUTTON; 		
    
    paddedRect = new ofxUIRectangle(-padding, -padding, w+padding*2.0, h+padding*2.0);
    paddedRect->setParent(rect); 
    
    setValue(_value); 
    img = new ofImage(); 
    img->loadImage(_pathURL);         
}

void ofxUIImageButton::setDrawPadding(bool _draw_padded_rect)
{
    draw_padded_rect = _draw_padded_rect; 
}

void ofxUIImageButton::setDrawPaddingOutline(bool _draw_padded_rect_outline)
{
    draw_padded_rect_outline = _draw_padded_rect_outline; 
}  


void ofxUIImageButton::drawBack()
{
                
    if(draw_back)
    {
        ofFill(); 
        ofSetColor(color_back); 
        img->draw(rect->getX(), rect->getY(), rect->getWidth(), rect->getHeight()); 
    }
}

void ofxUIImageButton::drawFill()
{
    if(draw_fill)
    {
        ofFill(); 
        ofSetColor(color_fill); 
        img->draw(rect->getX(), rect->getY(), rect->getWidth(), rect->getHeight()); 
    }
}

void ofxUIImageButton::drawFillHighlight()
{
    if(draw_fill_highlight)
    {
        ofFill(); 
        ofSetColor(color_fill_highlight); 
        img->draw(rect->getX(), rect->getY(), rect->getWidth(), rect->getHeight());             
    }
}   

void ofxUIImageButton::drawOutlineHighlight()
{
    if(draw_outline_highlight)
    {
        ofNoFill();
        ofSetColor(color_outline_highlight); 
        img->draw(rect->getX(), rect->getY(), rect->getWidth(), rect->getHeight()); 
    }
}   

void ofxUIImageButton::stateChange()
{        
    switch (state) {
        case OFX_UI_STATE_NORMAL:
        {            
            draw_fill_highlight = false;             
            draw_outline_highlight = false;  
        }
            break;
        case OFX_UI_STATE_OVER:
        {
            draw_fill_highlight = false;            
            draw_outline_highlight = true;  
        }
            break;
        case OFX_UI_STATE_DOWN:
        {
            draw_fill_highlight = true;            
            draw_outline_highlight = false;             
        }
            break;
        case OFX_UI_STATE_SUSTAINED:
        {
            draw_fill_highlight = false;            
            draw_outline_highlight = false;                         
        }
            break;            
            
        default:
            break;
    }        
}

void ofxUIImageButton::setParent(ofxUIWidget *_parent)
{
    parent = _parent; 
}	

void ofxUIImageButton::setValue(bool _value)
{
    value = _value;         
    draw_fill = value; 
}	

void ofxUIImageButton::setVisible(bool _visible)
{
    visible = _visible; 
}
