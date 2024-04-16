Graphics
    common attributes
        position(vertex: local)
        texture coordinate(uv coordinate)
    other data
        texture
        matrix(model, view, projection)

    mvp (model, view, projection)
        model: model -> world
        view: world -> view
        projection: view -> projection(the intersection between ray and surface)

    cube map
        six face texture

    framebuffers
        color buffer
        depth buffer
        stencil buffer
        post-processing
            pixel algorithm

    Shadow Map/Directional Shadow Map/Depth Map
        two pass(rendering depth map by depth test, render scene with depth map)
        shadow acne
            why
                the angle between light and surface
                surface is far away from light(several fragment sample same depth)
            shadow bias(reduce the distance)
                peter panning(front face culling when rendering depth map)
        over sampling
            depth texture: gl_repeat
            make shadow 0.0 when depth larger than 1.0
        jagged edge
            increasing the depth map resolution
            pcf(percentage-closer filtering)
    Point Shadow/Omnidirectional Shadow Map/Depth Cubemap

    Normal Map
        tangent space(tangent, bitangent, normal)
    Parallax Map
        steep parallax map
        parallax occlusion map

    HDR(High Dynamic Range)
        LDR: Low dynamic range(0.0 - 1.0)
        Tone mapping is the process transforming floating point color value to 
            LDR without lose too much detail.

    anti-aliasing
        MSAA(multiple sample anti-aliasing)

    Phong lighting model(light strenth factor)
        ambient(light * diffuse sampler)
        diffuse(light * diff * diffuse sampler)
        specular lighting(light * spec * specular sampler) 
    Blinn-Phong
        halfway vector : normalize(light dir + view dir)
        the angle of halfway vector and normal vector decide the power of specular

    light caster
        directional light(parallel, dir)
        point light
            intensity = 1 / (Kc + Kl * d + Kq * d * d)
                Kc -> constant
                Kl -> linear
                Kq -> quadratic
        spot light
            position
            direction
            radius(cos)
            [dim]

    gamma correct
        crt monitor : pow(input color, gamma)
        input color = pow(color, 1 / gamma) 

    Deferred shader/Deferred rendering
        We do deferred rendering with two pass of geometry pass
        and lighting pass.
        We render everything at geometry pass and store the 
        infomation that is needed by after lighting rendering into
        G-buffer.
        In lighting rendering we iterate G-buffer to caculate light.

        The disadvantages of deferred rendering is memory overhead for
        G-buffer and can't blend.

    SSAO(screen-space ambient occlusion)
        SSAO determines the ambient intensity of a fragment by comparing its
            depth value with its surrounding fragment's depth value.
    
    Assimp
        nodes
        meshes
        materials

        node
            childern
            meshes

        mesh
            vertices
            normals
            textureCoords
            indices
            material
        
        material
            texture

    pbr(physically based rendering)
        The theory of microfacet
            The theory describes that any surface at a microscopic scale
                can be described by tiny little perfectly reflective mirrors
                called microfacet. 
        Energy Conservation
            Outgoing light energy should never exceed the incoming light energy.
            Reflection and refraction
            Metallic and dielectrics.
        The Reflectance equation
            Radiometry
